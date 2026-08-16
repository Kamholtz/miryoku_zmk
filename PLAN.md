# Agent task: Make `Kamholtz/zmk-sofle` compatible with Miryoku + upstream ZMK

## Progress log

- [x] Phase 1: branch `upstream-zmk-miryoku` created in `C:\Users\carlk\repos\zmk-sofle` (2026-08-16)
- [x] Phase 2: full inventory done — DYA refs only in the two overlays, the two `.conf` files, `config/west.yml` (left alone per Phase 10), and READMEs (docs only)
- [x] Phase 3: left overlay — removed `battery_history_request.dtsi` + `runtime-input-processor.dtsi`; hardware untouched (commit 8158623)
- [x] Phase 4: right overlay — removed `battery_history_request.dtsi` (commit 8158623)
- [x] Phase 5: re-search clean — no DYA refs left under `boards/`
- [x] Phase 6: `eyelash_sofle.dtsi` has no DYA node references; unchanged
- [x] Phase 7: `.conf` cleanup (commit f923d1e). Removed symbols verified absent from upstream ZMK: `ZMK_BLE_MANAGEMENT*`, `ZMK_RUNTIME_INPUT_PROCESSOR*`, `ZMK_SETTINGS_RPC*`, `ZMK_RUNTIME_SENSOR_ROTATE*`, `ZMK_BATTERY_HISTORY*`, `ZMK_SPLIT_RELAY_EVENT`. Kept (verified upstream): `ZMK_STUDIO`, `ZMK_POINTING`, `ZMK_SETTINGS_SAVE_DEBOUNCE`, `ZMK_SPLIT_BLE_CENTRAL_SPLIT_RUN_STACK_SIZE`, `ZMK_HID_REPORT_TYPE_NKRO`. Done before first build because undefined Kconfig symbols abort the Zephyr build.
- [x] Phase 8: `Kconfig.shield` / `Kconfig.defconfig` are clean upstream-style; both shields exposed; unchanged
- [x] Phase 9: HWMv2 `boards/shields/eyelash_sofle/` layout preserved
- [x] Phase 10: `config/west.yml` deliberately not modified
- [x] Phase 11: committed and pushed `upstream-zmk-miryoku` to `Kamholtz/zmk-sofle` (commits 8158623, f923d1e)
- [ ] Phase 12–14: point Miryoku workflow at fork branch
- [x] Phase 15–17: first integration run failed (both halves) but the battery_history missing-file error is gone and the shield conf loaded from the Kamholtz fork. CI logs need sign-in, so the build was reproduced exactly in the local `zmkfirmware/zmk-build-arm:stable` container. First genuine error: `config/eyelash_sofle.conf` set `CONFIG_WS2812_STRIP=y`, a symbol Zephyr split into per-bus symbols (`WS2812_STRIP_SPI` etc.) that now auto-enable from the devicetree — line removed. Left build then produced zmk.uf2 locally with Studio snippet + nice_view.
- [ ] Phase 18–22: feature preservation checks + functional validation (on-device, user)
- [ ] Phase 23: pin a tag once validated
- [ ] Phase 24: add MIRYOKU_UPSTREAM_ZMK.md to the fork

## Objective

Modify the user's fork:

```text
Kamholtz/zmk-sofle
```

so that its **Eyelash Sofle HWMv2 shield** can be used by:

```text
Kamholtz/miryoku_zmk
```

with:

```text
Miryoku
+ upstream ZMK main
+ Zephyr 4.1
+ nice_nano//zmk
+ nice_view
+ official ZMK Studio
```

Do **not** migrate Miryoku to Cormoran's DYA ZMK fork.

Do **not** add DYA/Cormoran modules unless a later build proves a hardware feature genuinely requires one and there is no upstream-ZMK equivalent.

The immediate problem is that the current fork still contains DYA-specific dependencies:

* `eyelash_sofle_left.overlay` includes both `battery_history_request.dtsi` and `runtime-input-processor.dtsi`.
* `eyelash_sofle_right.overlay` includes `battery_history_request.dtsi`.

---

# Phase 1: Establish a safe working branch

## 1. Clone or open the fork

Work in:

```bash
git clone https://github.com/Kamholtz/zmk-sofle.git
cd zmk-sofle
```

If already cloned:

```bash
git fetch origin
git switch main
git pull --ff-only
```

## 2. Create a dedicated branch

Do not make the compatibility work directly on `main`.

For example:

```bash
git switch -c upstream-zmk-miryoku
```

The intention is:

```text
main
└── remains close to original fork

upstream-zmk-miryoku
└── removes DYA-specific dependencies
    └── intended for Kamholtz/miryoku_zmk
```

Do not delete the vendor/DYA code from `main`.

---

# Phase 2: Inventory the fork before changing it

## 3. Inspect the Eyelash Sofle shield

The important directory is:

```text
boards/shields/eyelash_sofle/
```

Inspect all files, especially:

```text
Kconfig.defconfig
Kconfig.shield
eyelash_sofle-layouts.dtsi
eyelash_sofle.dtsi
eyelash_sofle_left.conf
eyelash_sofle_left.overlay
eyelash_sofle_right.conf
eyelash_sofle_right.overlay
```

## 4. Search the entire repository for DYA/Cormoran dependencies

Run:

```bash
rg -n \
  'battery_history|battery-history|runtime.input|runtime-input|settings.rpc|settings-rpc|ble.management|ble-management|cormoran|dya|DYA' .
```

Also search configuration symbols:

```bash
rg -n 'CONFIG_.*(BATTERY|RUNTIME|RPC|DYA|BLE_MANAGEMENT)' .
```

Record every match before editing anything.

Classify each result as one of:

```text
A. Hardware definition
B. Normal upstream ZMK functionality
C. DYA/Cormoran-only functionality
D. Example/build configuration not used by Miryoku
```

Do not remove something merely because its name sounds unfamiliar.

---

# Phase 3: Remove the confirmed DYA-only devicetree dependencies

## 5. Edit the left overlay

File:

```text
boards/shields/eyelash_sofle/eyelash_sofle_left.overlay
```

It currently starts with:

```dts
#include "eyelash_sofle.dtsi"
#include <behaviors/battery_history_request.dtsi>
#include <input/processors.dtsi>
#include <input/processors/runtime-input-processor.dtsi>
```

Change this to:

```dts
#include "eyelash_sofle.dtsi"
#include <input/processors.dtsi>
```

Remove exactly:

```dts
#include <behaviors/battery_history_request.dtsi>
#include <input/processors/runtime-input-processor.dtsi>
```

### Do not change the hardware definitions underneath

Keep the existing:

```dts
&kscan0
```

configuration.

Keep all:

```text
row-gpios
col-gpios
```

unchanged.

Keep:

```dts
&left_encoder {
    status = "okay";
};
```

unchanged.

The first patch should remove software dependencies only.

---

# Phase 4: Fix the right overlay

## 6. Edit:

```text
boards/shields/eyelash_sofle/eyelash_sofle_right.overlay
```

It currently starts with:

```dts
#include "eyelash_sofle.dtsi"
#include <behaviors/battery_history_request.dtsi>
```

Change it to:

```dts
#include "eyelash_sofle.dtsi"
```

Remove exactly:

```dts
#include <behaviors/battery_history_request.dtsi>
```

### Do not change

Keep the right matrix definitions unchanged.

Keep:

```dts
&default_transform {
    col-offset = <7>;
};
```

unchanged.

---

# Phase 5: Check whether those modules are referenced elsewhere

## 7. Search again

After those edits:

```bash
rg -n \
  'battery_history|battery-history|runtime-input-processor|settings-rpc|ble-management|cormoran|dya|DYA' \
  boards/shields/eyelash_sofle
```

The immediate goal is that the **shield hardware definition itself** no longer requires Cormoran modules.

If matches remain, investigate each one.

Do not automatically remove them.

---

# Phase 6: Inspect the shared `.dtsi`

## 8. Inspect:

```text
boards/shields/eyelash_sofle/eyelash_sofle.dtsi
```

Look for references to nodes or labels provided by:

```text
zmk-module-battery-history
zmk-module-runtime-input-processor
zmk-module-settings-rpc
zmk-module-ble-management
```

Examples of suspicious references would be nodes resembling:

```text
battery_history
battery_history_request
runtime_input_processor
settings_rpc
```

If none exist, make no changes.

### Preserve hardware functionality

Do not remove ordinary definitions for:

```text
key matrix
GPIO
encoders
display
SPI/I2C
split transport
RGB/backlight
external power
pointing/input
physical layout
```

unless a build error later demonstrates a specific incompatibility.

---

# Phase 7: Inspect both `.conf` files

## 9. Inspect:

```text
boards/shields/eyelash_sofle/eyelash_sofle_left.conf
boards/shields/eyelash_sofle/eyelash_sofle_right.conf
```

Look for Kconfig symbols supplied specifically by the removed Cormoran modules.

Use:

```bash
rg -n 'CONFIG_' \
  boards/shields/eyelash_sofle/eyelash_sofle_left.conf \
  boards/shields/eyelash_sofle/eyelash_sofle_right.conf
```

For every unusual symbol, determine whether it exists in upstream ZMK.

### Only remove a symbol if:

1. it comes from one of the DYA/Cormoran modules, and
2. upstream ZMK does not provide it, and
3. the physical keyboard does not require an equivalent upstream feature.

Do not remove standard options just to simplify the file.

---

# Phase 8: Inspect Kconfig files

## 10. Check:

```text
boards/shields/eyelash_sofle/Kconfig.defconfig
boards/shields/eyelash_sofle/Kconfig.shield
```

The shield definitions must continue to expose:

```text
eyelash_sofle_left
eyelash_sofle_right
```

for:

```bash
-SHIELD=eyelash_sofle_left
```

and:

```bash
-SHIELD=eyelash_sofle_right
```

Do not convert them back into boards.

The new architecture is deliberately:

```text
Board:
nice_nano//zmk

Shield:
eyelash_sofle_left
```

not:

```text
Board:
eyelash_sofle_left
```

---

# Phase 9: Do not undo the HWMv2 conversion

This is an important constraint.

The fork currently has the modern structure:

```text
boards/shields/eyelash_sofle/
```

Keep it.

Do **not** restore the old:

```text
boards/arm/eyelash_sofle/
```

layout from pre-2026 commits.

The Miryoku build has already successfully reached:

```text
Board: nice_nano
Revision: 2.0.0
qualifiers: nrf52840/zmk

Shield(s):
eyelash_sofle_left nice_view
```

So the HWMv2 conversion itself is working.

The problem is the additional DYA dependency layer, not the board/shield architecture.

---

# Phase 10: Decide what to do with the fork's `config/west.yml`

The source repository's standalone firmware configuration may contain something like:

```yaml
zmk:
  remote: cormoran
  revision: v0.3-branch+dya
```

along with Cormoran modules.

**Do not modify this initially.**

Why:

The Miryoku workflow consumes `Kamholtz/zmk-sofle` as an **external ZMK module**. Its own standalone `config/west.yml` is not necessarily relevant to that use.

The objective of this branch is first to make:

```text
boards/shields/eyelash_sofle/
```

usable by upstream ZMK.

Changing unrelated standalone build infrastructure would unnecessarily increase the patch.

If later testing shows module discovery actually consumes a manifest from the fork, reassess then.

---

# Phase 11: Commit the minimal fork change

At this stage the first commit should ideally modify only:

```text
eyelash_sofle_left.overlay
eyelash_sofle_right.overlay
```

unless inspection found another confirmed direct dependency.

Review:

```bash
git diff
```

The diff should approximately show:

```diff
--- a/boards/shields/eyelash_sofle/eyelash_sofle_left.overlay
+++ b/boards/shields/eyelash_sofle/eyelash_sofle_left.overlay

 #include "eyelash_sofle.dtsi"
-#include <behaviors/battery_history_request.dtsi>
 #include <input/processors.dtsi>
-#include <input/processors/runtime-input-processor.dtsi>
```

and:

```diff
--- a/boards/shields/eyelash_sofle/eyelash_sofle_right.overlay
+++ b/boards/shields/eyelash_sofle/eyelash_sofle_right.overlay

 #include "eyelash_sofle.dtsi"
-#include <behaviors/battery_history_request.dtsi>
```

Commit:

```bash
git add boards/shields/eyelash_sofle/
git commit -m "Remove DYA-only dependencies from Eyelash Sofle shield"
git push -u origin upstream-zmk-miryoku
```

---

# Phase 12: Point Miryoku at the fork branch

Now work in:

```text
Kamholtz/miryoku_zmk
```

The relevant workflow is:

```text
.github/workflows/0-my-eyelash-sofle.yml
```

## 12. Replace the vendor module

Find:

```yaml
modules: '["a741725193/zmk-sofle/main"]'
```

Change it to:

```yaml
modules: '["Kamholtz/zmk-sofle/upstream-zmk-miryoku"]'
```

Do this for both left and right jobs if both specify the module independently.

---

# Phase 13: Preserve the working board/shield settings

The workflow must continue using:

### Left

```yaml
board: '["nice_nano//zmk"]'
shield: '["eyelash_sofle_left nice_view"]'
```

### Right

```yaml
board: '["nice_nano//zmk"]'
shield: '["eyelash_sofle_right nice_view"]'
```

Do not change these again unless a subsequent build demonstrates a real problem.

---

# Phase 14: Preserve official ZMK Studio

For the left/central half, keep:

```yaml
CONFIG_ZMK_STUDIO=y
CONFIG_ZMK_STUDIO_LOCKING=n
```

and:

```yaml
snippet: '["studio-rpc-usb-uart"]'
```

Do not add DYA Studio configuration.

The desired runtime configurator remains **official ZMK Studio**.

---

# Phase 15: Run the first integration build

Commit the Miryoku workflow change and trigger GitHub Actions.

The first validation target is not necessarily a completely successful build.

It is:

> Verify that the old missing battery-history file error disappears.

The following must no longer occur:

```text
fatal error:
behaviors/battery_history_request.dtsi:
No such file or directory
```

---

# Phase 16: Verify that the correct fork was actually loaded

Inspect the Actions log.

It should show a module path corresponding to:

```text
Kamholtz-zmk-sofle-upstream-zmk-miryoku
```

or equivalent.

It must **not** still show:

```text
modules/a741725193-zmk-sofle-main
```

for the Eyelash Sofle shield.

The loaded overlay should come from the user's fork.

Also confirm:

```text
Board: nice_nano
Revision: 2.0.0
qualifiers: nrf52840/zmk
```

and:

```text
Shield(s): eyelash_sofle_left nice_view
```

for the left build.

---

# Phase 17: Handle the next error methodically

If the build fails again, stop and inspect the **first genuine compiler/CMake/Kconfig/devicetree error**.

Do not make speculative bulk changes.

Use this decision tree:

```text
New error
   │
   ├── Missing Cormoran/DYA file?
   │       │
   │       └── Find reference in Kamholtz/zmk-sofle
   │           and determine whether it can be removed.
   │
   ├── Unknown CONFIG_* symbol?
   │       │
   │       └── Determine whether it belongs to
   │           Cormoran/DYA or upstream ZMK.
   │
   ├── Devicetree syntax/binding error?
   │       │
   │       └── Adapt the specific HWMv2 definition
   │           to current upstream ZMK.
   │
   ├── Miryoku keymap error?
   │       │
   │       └── Fix in miryoku_zmk, not zmk-sofle.
   │
   └── Nice!View/ZMK Studio error?
           │
           └── Treat separately from Sofle hardware.
```

Make **one logical compatibility fix per iteration**.

Build again after each fix.

---

# Phase 18: Important feature-preservation rule

Do not remove a feature simply because it causes a compilation error.

First determine whether the feature is:

### DYA-specific convenience functionality

Examples:

```text
battery history
DYA settings RPC
DYA-specific runtime configuration
```

These can usually be removed for this objective.

### Actual keyboard hardware functionality

Examples:

```text
matrix scanning
encoders
Nice!View
split communication
battery voltage reporting
pointing support
RGB/backlight
power control
```

These must be preserved or replaced with their upstream-ZMK equivalent.

---

# Phase 19: Pay special attention to battery functionality

Removing:

```dts
#include <behaviors/battery_history_request.dtsi>
```

does **not** mean normal battery reporting should intentionally be removed.

The target is:

```text
Normal ZMK battery percentage/reporting   KEEP
Cormoran battery-history extension        REMOVE
```

After firmware builds, test battery display/status independently.

---

# Phase 20: Get left firmware compiling first

Prioritise:

```text
nice_nano//zmk
+
eyelash_sofle_left
+
nice_view
+
Miryoku
+
ZMK Studio
```

The left side is more complex because it is the central half and has Studio enabled.

Do not start redesigning the right side while unresolved left-side errors remain, unless the same source change clearly affects both.

---

# Phase 21: Then validate the right half

Once left succeeds, verify:

```text
nice_nano//zmk
+
eyelash_sofle_right
+
nice_view
+
Miryoku
```

produces its own UF2.

Check that split-specific configuration remains correct.

---

# Phase 22: Functional validation after compile success

A successful compiler run is not enough.

After flashing, verify:

1. All physical keys work.
2. Left and right halves connect.
3. Correct key positions are reported.
4. Encoders work.
5. Both Nice!View displays work.
6. USB works.
7. Bluetooth works if used.
8. Sleep/wake works.
9. Normal battery percentage works.
10. Miryoku layers work.
11. Miryoku combos and hold-taps work.
12. Mouse/pointing functionality behaves as expected.
13. Official ZMK Studio connects to the left half.
14. ZMK Studio can change a test key and retain the change.

---

# Phase 23: Only after successful testing, make the dependency stable

Do not leave production Miryoku configuration pointing indefinitely at:

```text
upstream-zmk-miryoku
```

or:

```text
main
```

Create a tag in the fork, for example:

```bash
git tag miryoku-upstream-zmk-v1
git push origin miryoku-upstream-zmk-v1
```

Then change the Miryoku workflow to:

```yaml
modules: '["Kamholtz/zmk-sofle/miryoku-upstream-zmk-v1"]'
```

This prevents future changes in the Sofle fork from silently changing firmware builds.

A commit SHA is even more reproducible if the Miryoku module loader supports it cleanly.

---

# Phase 24: Document why the fork branch exists

Add a short file such as:

```text
MIRYOKU_UPSTREAM_ZMK.md
```

to `Kamholtz/zmk-sofle`.

Suggested contents:

```markdown
# Upstream ZMK / Miryoku compatibility

This branch is intended for use as an external ZMK module by
Kamholtz/miryoku_zmk.

It retains the Eyelash Sofle HWMv2 shield but removes dependencies
introduced for the Cormoran/DYA firmware stack.

Target stack:

- upstream ZMK
- Zephyr 4.1+
- nice_nano//zmk
- eyelash_sofle_left / eyelash_sofle_right shields
- Nice!View
- Miryoku
- official ZMK Studio

DYA-specific battery history and runtime configuration modules are
intentionally not required.
```

---

# Agent guardrails

The agent should **not**:

* switch Miryoku to `cormoran/zmk`;
* add the complete DYA dependency tree;
* revert to `eyelash_sofle_left` as a board;
* revert the shield to old `boards/arm` HWMv1 format;
* replace `nice_nano//zmk` with `nice_nano_v2`;
* remove Nice!View support;
* remove ordinary ZMK battery reporting;
* remove encoder or matrix definitions;
* disable official ZMK Studio;
* rewrite unrelated configuration pre-emptively;
* make several speculative compatibility fixes before rebuilding.

The agent **should**:

```text
inspect
→ make smallest confirmed change
→ build
→ inspect first new error
→ make next confirmed change
→ repeat
```

## Definition of done

The task is complete when:

```text
Kamholtz/miryoku_zmk
        │
        ├── upstream ZMK
        │
        ├── nice_nano//zmk
        │
        ├── nice_view
        │
        └── Kamholtz/zmk-sofle/<pinned-compatible-ref>
                         │
                         └── Eyelash Sofle HWMv2 shield
                             with no required DYA/Cormoran modules
```

successfully produces **left and right UF2 firmware**, and basic keyboard, split, display, encoder, battery and ZMK Studio functionality have been verified.

The very first implementation should therefore be deliberately small: **remove the three confirmed DYA-specific include lines from the two overlays, point Miryoku at your fork branch, and rebuild before doing anything else.**
