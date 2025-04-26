// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_EYELASH_SOFLE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
/*  00: ESC       01: 1         02: 2         03: 3         04: 4         05: 5         06: ↑         07: 6         08: 7         09: 8         10: 9         11: 0         12: -        */ \
    &kp ESC       &kp N1        &kp N2        &kp N3        &kp N4        &kp N5        &kp UP        &kp N6        &kp N7        &kp N8        &kp N9        &kp N0        &kp MINUS  \
/*  13: TAB       14: Q         15: W         16: E         17: R         18: T         19: ↓         20: Y         21: U         22: I         23: O         24: P         25: \\       */ \
    &kp TAB       K00           K01           K02           K03           K04           &kp DOWN      K05           K06           K07           K08           K09           &kp BSLH  \
/*  26: CTRL      27: A         28: S         29: D         30: F         31: G         32: ←         33: H         34: J         35: K         36: L         37: ;         38: '        */ \
    &kp LCTRL     K10           K11           K12           K13           K14           &kp LEFT      K15           K16           K17           K18           K19           &kp SQT  \
/*  39: ⇧         40: Z         41: X         42: C         43: V         44: B         45: →         46: N         47: M         48: ,         49: .         50: /         51: ⏎       */ \
    &sk LSHFT     K20           K21           K22           K23           K24           &kp RIGHT     K25           K26           K27           K28           K29           &kp RET  \
/*                52:           53: CTRL      54: GUI       55:           56:           57:           58: ⏎         59:           60:           61:           62: ⇧         63: ⌥       */ \
                  XXX           &kp LCTRL     &kp LGUI      K31           K33           K34           &kp RET       K35           K36           K37           &sk RSHFT     &kp RALT


// REFERENCE: zmk-docs/modifiers.md

#define MIRYOKU_LAYERMAPPING_NAV( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
/*   0: Esc            1: 1         2: 2         3: 3         4: 4         5: 5         6: ↑          7: 6         8: 7         9: 8        10: 9       11: 0      12: -      */ \
    &kp ESC           &kp LG(N1)   &kp LG(N2)   &kp LG(N3)   &kp LG(N4)   &kp LG(N5)   &kp UP        &kp LG(N6)   &kp LG(N7)   &kp LG(N8)  &kp LG(N9)  &kp LG(N0)  &kp MINUS \
/*  13: ⇢            14: Q        15: W        16: E        17: R        18: T        19: ↓         20: Y        21: U        22: I        23: O       24: P      25: \      */ \
    &kp LG(LC(RIGHT)) K00          K01          K02          K03          K04          &kp DOWN     K05          K06          K07          K08         K09         &kp BSLH \
/*  26: ⇠            27: A        28: S        29: D        30: F        31: G        32: ←        33: H        34: J        35: K        36: L       37: ;      38: '      */ \
    &kp LG(LC(LEFT))  K10          K11          K12          K13          K14          &kp LEFT     K15          K16          K17          K18         K19         &kp SQT \
/*  39: ⇧             40: Z        41: X        42: C        43: V        44: B        45: →        46: N        47: M        48:          49: .       50: /      51: ⏎     */ \
    &sk LSHFT         K20          K21          K22          K23          K24          &kp RIGHT    K25          K26          K27          K28         K29         &kp RET \
/*  52:               53: ⌃        54: ⌘        55:          56:          57:          58: ⏎        59:          60:          61:          62: ⇧       63: ⌥     */ \
    XXX               &kp LCTRL    &kp LGUI     K32          K33          K34          &kp RET      K35          K36          K37          &sk RSHFT   &kp RALT

#define MIRYOKU_LAYER_NAV \
/*  00: BOOT      01: to TAP    02: to EXTRA    03: to BASE   04:           05: RDO       06: PST       07: CPY       08: CUT       09: UND      */ \
    U_BOOT,       &u_to_U_TAP,  &u_to_U_EXTRA,  &u_to_U_BASE, U_NA,         U_RDO,        U_PST,        U_CPY,        U_CUT,        U_UND, \
/*  10: GUI       11: ALT       12: CTRL        13: SHFT      14:           15: ←         16: ↓         17: ↑         18: →         19: CAPS    */ \
    &kp LGUI,     &kp LALT,     &kp LCTRL,      &kp LSHFT,    U_NA,         &kp LEFT,     &kp DOWN,     &kp UP,       &kp RIGHT,    &u_caps_word, \
/*  20: STU       21: RALT      22: to NUM      23: to NAV    24: BSPC      25: HOME      26: PG_DN     27: PG_UP     28: END       29: INS     */ \
    U_STU,        &kp RALT,     &u_to_U_NUM,    &u_to_U_NAV,  &kp BSPC,     &kp HOME,     &kp PG_DN,    &kp PG_UP,    &kp END,      &kp INS, \
/*  30:           31:           32:             33:           34:           35: RET       36: BSPC      37: DEL       38:           39:        */ \
    U_NP,         U_NP,         U_NA,           U_NA,         U_NA,         &kp RET,      &kp BSPC,     &kp DEL,      U_NP,         U_NP

#define MIRYOKU_LAYERMAPPING_SYM( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39  \
) \
/*  00: `       01: [        02: (          03: )        04: ]       05: .            06: ↑           07: `         08: 7        09: 8        10: 9         11: 0         12: -      */ \
    &kp GRAVE   &kp LBKT     &kp LPAR       &kp RPAR     &kp RBKT    &kp DOT          &kp UP          &kp GRAVE     &kp LG(N7)   &kp LG(N8)   &kp LG(N9)    &kp LG(N0)    &kp MINUS \
/*  13: !       14: ,        15: {          16: }        17: ;       18: ?            19: ↓           20: "         21: @        22: :        23: O         24: P         25: \      */ \
    &kp EXCL    &kp COMMA    &kp LBRC       &kp RBRC     &kp SEMI    &kp QMARK        &kp DOWN        &kp DQT       &kp AT       &kp COLON    K08           K09           &kp BSLH \
/*  26: #       27: ^        28: =          29: _        30: $       31: *            32: ←           33: '         34: K        35: L        36: ;         37: K         38: '      */ \
    &kp HASH    &kp CARET    &kp EQUAL      &kp UNDER    &kp DLLR    &kp ASTRK        &kp LEFT        &kp SQT       K16          K17          K18           K19           &kp SQT \
/*  39: ~       40: <        41: |          42: -        43: >       44: /            45: →           46: \         47: %        48: +        49: &         50: K29       51: ⏎     */ \
    &kp TILDE   &kp LT       &kp PIPE       &kp MINUS    &kp GT      &kp SLASH        &kp RIGHT       &kp BSLH      &kp PRCNT    &kp PLUS     &kp AMPS      K29           &kp RET \
/*  52:         53: ⌃        54: ⌘          55:          56:         57:              58: ⏎           59:           60:          61:          62: ⇧         63: ⌥     */ \
    XXX         &kp LCTRL    &kp LGUI       K32          K33         K34              &kp RET         K35           K36          K37          &sk RSHFT     &kp RALT

// we
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTPINKIE 15 16
// er
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTINNERINDEX 16 17
// ui
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTINNERINDEX 21 22
// io
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTPINKIE 22 23
/*#define MIRYOKU_KLUDGE_TOPROWCOMBOS*/

#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTPINKIE 41 42
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTINNERINDEX 42 43
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTINNERINDEX 47 48
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTPINKIE 48 49

#define MIRYOKU_CUSTOM_COMBOS_UNDO 40 41
#define MIRYOKU_CUSTOM_COMBOS_CUT 41 42
#define MIRYOKU_CUSTOM_COMBOS_COPY 42 43
#define MIRYOKU_CUSTOM_COMBOS_PASTE 43 44

#define MIRYOKU_CUSTOM_COMBOS_LBKT 21 22
#define MIRYOKU_CUSTOM_COMBOS_RBKT 22 23
#define MIRYOKU_CUSTOM_COMBOS

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 56 57
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 59 60
#define MIRYOKU_KLUDGE_THUMBCOMBOS



#define MIRYOKU_LAYER_TAP \
/*  00: Q        01: W        02: E        03: R        04: T        05: Y        06: U        07: I        08: O        09: P      */ \
    &kp Q,       &kp W,       &kp E,       &kp R,       &kp T,       &kp Y,       &kp U,       &kp I,       &kp O,       &kp P, \
/*  10: A        11: S        12: D        13: F        14: G        15: H        16: J        17: K        18: L        19: ;      */ \
    &kp A,       &kp S,       &kp D,       &kp F,       &kp G,       &kp H,       &kp J,       &kp K,       &kp L,       &kp SEMI, \
/*  20: Z        21: X        22: C        23: V        24: B        25: N        26: M        27: ,        28: .        29: /      */ \
    &kp Z,       &kp X,       &kp C,       &kp V,       &kp B,       &kp N,       &kp M,       &kp COMMA,   &kp DOT,     &kp SLASH, \
/*  30:          31:          32: ESC      33: SPACE    34: TAB      35: RET      36: BSPC     37: DEL      38:          39:         */ \
    U_NP,        U_NP,        &kp ESC,     &kp SPACE,   &kp TAB,     &kp RET,     &kp BSPC,    &kp DEL,     U_NP,        U_NP

// NOTE: comments for mod taps are wrong
#define MIRYOKU_LAYER_BASE \
/*  00: Q              01: W            02: E               03: R               04: T               05: Y             06: U               07: I               08: O               09: P             */ \
    &kp Q,             &kp W,           &kp E,              &kp R,              &kp T,              &kp Y,            &kp U,              &kp I,              &kp O,              &kp P, \
/*  10: GUI+A          11: ALT+S        12: CTRL+D          13: SHFT+F          14: G               15: H             16: SHFT+J          17: CTRL+K          18: ALT+L           19: GUI+;         */ \
    U_MTL(LGUI, A),    U_MTL(LALT, S),  U_MTL(LCTRL, D),    U_MTL(LSHFT, F),    &kp G,              &kp H,            U_MTR(LSHFT, J),    U_MTR(LCTRL, K),    U_MTR(LALT, L),     U_MTR(LGUI, SEMI), \
/*  20: Z (BTN)        21: RALT+X       22: C               23: V               24: B               25: N             26: M               27: ,               28: RALT+.          29: / (BTN)      */ \
    U_LT(U_BUTTON, Z), U_MTL(RALT, X),  &kp C,              &kp V,              &kp B,              &kp N,            &kp M,              &kp COMMA,          U_MTR(RALT, DOT),   U_LT(U_BUTTON, SLASH), \
/*  30:                31:              32: ESC (MEDIA)     33: SPACE (NAV)     34: TAB (MOUSE)     35: RET (SYM)     36: BSPC (NUM)      37: DEL (FUN)       38:                 39:              */ \
    U_NP,              U_NP,            U_LT(U_MEDIA, ESC), U_LT(U_NAV, SPACE), U_LT(U_MOUSE, TAB), U_LT(U_SYM, RET), U_LT(U_NUM, BSPC),  U_LT(U_FUN, DEL),   U_NP,               U_NP

#define MIRYOKU_LAYER_NUM \
/*  00: [        01: 7      02: 8       03: 9       04: ]        05:           06: to BASE     07: to EXTRA     08: to TAP       09: BOOT         */ \
    &kp LBKT,    &kp N7,    &kp N8,     &kp N9,     &kp RBKT,    U_NA,         &u_to_U_BASE,   &u_to_U_EXTRA,   &u_to_U_TAP,     U_BOOT, \
/*  10: ;        11: 4      12: 5       13: 6       14: =        15: BSPC      16: LSHFT       17: LCTRL        18: LALT         19: LGUI         */ \
    &kp SEMI,    &kp N4,    &kp N5,     &kp N6,     &kp EQUAL,   &kp BSPC,     &kp LSHFT,      &kp LCTRL,       &kp LALT,        &kp LGUI, \
/*  20: `        21: 1      22: 2       23: 3       24: \        25:           26: to NUM      27: to NAV       28: .            29: /            */ \
    &kp GRAVE,   &kp N1,    &kp N2,     &kp N3,     &kp BSLH,    U_NA,         &u_to_U_NUM,    &u_to_U_NAV,     &kp DOT,         &kp SLASH, \
/*  30:          31:        32: .       33: 0       34: -        35:           36:             37:              38:              39:              */ \
    U_NP,        U_NP,      &kp DOT,    &kp N0,     &kp MINUS,   U_NA,         U_NA,           U_NA,            U_NP,            U_NP

/*https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/miryoku_for_programming/ */
/*      ` ~ # & |    ^ { } [ ]      */
/*      ! _ : = $    @ ( ) _ ;      */
/*      % ? * + \    / - < > "      */

#define MIRYOKU_LAYER_SYM \
/*  00: `               01: ~                  02: #                  03: &                  04: |           05: ^           06: [                07: ]                 08: ⎡                09: ⎤ */ \
    &kp GRAVE,          &kp TILDE,             &kp HASH,              &kp AMPS,              &kp PIPE,       &kp CARET,      &kp LBRC,            &kp RBRC,             &kp LBKT,           &kp RBKT, \
/*  12: GUI+!           13: ALT+_              14: CTRL+:             15: SHFT+=             16: $           17: @           18: (+SHFT)          19: )+CTRL            20: _+ALT           21: ;+GUI      */ \
    U_MTL(LGUI, EXCL),  U_MTL(LALT, UNDER),    U_MTL(LCTRL, COLON),   U_MTL(LSHIFT, EQUAL),  &kp DLLR,       &kp AT,         U_MTR(LSHIFT, LPAR), U_MTR(LCTRL, RPAR),   U_MTR(LALT, UNDER), U_MTR(LGUI, SEMI), \
/*  22: %               23: ?                  24: *                  25: +                  26: \\          27: /           28: -                29: <                 30: >               31: \"         */ \
    &kp PRCNT,          &kp QMARK,             &kp ASTRK,             &kp PLUS,              &kp BSLH,       &kp SLASH,      &kp MINUS,           &kp LT,               &kp GT,             &kp DQT, \
/*  32:                 33:                    34: (                  35: )                  36: _           37:             38:                  39:                   40:                 41:            */ \
    U_NP,               U_NP,                  &kp LPAR,              &kp RPAR,              &kp UNDER,      U_NA,           U_NA,                U_NA,                 U_NP,               U_NP
