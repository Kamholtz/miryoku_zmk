---
title: "Modifiers | ZMK Firmware"
source: "https://zmk.dev/docs/keymaps/modifiers"
author:
published:
created: 2025-03-29
description: "Modifiers are the special keyboard keys: shift, alt, control & GUI. Their keycodes can be found in the list of keycodes."
tags:
  - "clippings"
---
Modifiers are the special keyboard keys: *shift*, *alt*, *control* & *GUI*. Their keycodes can be found in the [list of keycodes](https://zmk.dev/docs/keymaps/list-of-keycodes#modifiers). Modifiers can be used both as [keys](https://zmk.dev/docs/keymaps/#modifier-keys) and as [functions](https://zmk.dev/docs/keymaps/#modifier-functions).

### Modifier Keys​

These act like any other keycode.

- e.g. `&kp LEFT_GUI` pushes and releases the left GUI key.

### Modifier Functions​

Modifier functions add one or more modifiers to a code.

These functions take the form: `XX(code)`

- Modifier functions apply a modifier to a code:
- `&kp LS(A)` = `LEFT_SHIFT`+`A` (a capitalized **A**).
- They can be combined:
- `&kp LC(RA(B))` = `LEFT_CONTROL`+`RIGHT_ALT`+`B`
- They can be applied to a modifier keycode to create combined modifier keys:
- `&kp LS(LALT)` = `LEFT_SHIFT` + `LEFT_ALT`
- Some basic keycodes already include a modifier function in their definition:
- `DOLLAR` = `LS(NUMBER_4)`
- There are left- and right-handed versions of each modifier (also see [table in the list of keycodes](https://zmk.dev/docs/keymaps/list-of-keycodes#modifiers)):
- `LS(x)`, `LC(x)`, `LA(x)`, `LG(x)`, `RS(x)`, `RC(x)`, `RA(x)`, `RG(x)`
- Modified keys can safely be rolled-over. Modifier functions are released when another key is pressed.
- Press `&kp LS(A)`, then press `&kp B`, release `&kp LS(A)` and release `&kp B` results in **Ab**. Only the A is capitalized.
