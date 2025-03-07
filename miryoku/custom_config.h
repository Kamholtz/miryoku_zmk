// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define XXX &none


#define MIRYOKU_LAYOUTMAPPING_SOFLE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
&kp ESC     XXX  XXX  XXX  XXX  XXX         XXX         XXX  XXX  XXX  XXX  XXX  XXX \
&kp N1      K00  K01  K02  K03  K04         XXX         K05  K06  K07  K08  K09  XXX \
XXX         K10  K11  K12  K13  K14         XXX         K15  K16  K17  K18  K19  XXX \
XXX         K20  K21  K22  K23  K24         XXX         K25  K26  K27  K28  K29  XXX \
XXX              XXX  K32  K33  K34  XXX    XXX    XXX  K35  K36  K37  XXX

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_EYELASH_SOFLE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
&kp ESC   &kp N1  &kp N2    &kp N3    &kp N4  &kp N5      &kp UP            &kp N6  &kp N7  &kp N8     &kp N9   &kp N0  &kp BSPC \
&kp TAB   K00     K01       K02       K03     K04         &kp DOWN          K05     K06     K07        K08      K09     &kp PIPE \
&kp LCTRL K10     K11       K12       K13     K14         &kp LEFT          K15     K16     K17        K18      K19     &kp SQT  \
&kp LSHFT K20     K21       K22       K23     K24         &kp RIGHT         K25     K26     K27        K28      K29     &kp RET  \
XXX               &kp LCTRL &kp LGUI  K32     K33  K34    &kp RET      K35  K36     K37     &kp RSHFT  &kp RALT

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 53 54
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 55 56

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 53 54
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 55 56

#define MIRYOKU_LAYER_TAP \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&kp A,             &kp S,             &kp D,             &kp F,             &kp G,             &kp H,             &kp J,             &kp K,             &kp L,             &kp SEMI,           \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         &kp DOT,           &kp SLASH,         \
U_NP,              U_NP,              &kp ESC,           &kp SPACE,         &kp TAB,           &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
U_MTL(LGUI, A),     U_MTL(LALT, S),     U_MTL(LCTRL, D),    U_MTL(LSHFT, F),    &kp G,             &kp H,             U_MTR(LSHFT, J),    U_MTR(LCTRL, K),    U_MTR(LALT, L),     U_MTR(LGUI, SEMI),   \
U_LT(U_BUTTON, Z), U_MTL(RALT, X),     &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MTR(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

/*https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/miryoku_for_programming/ */
/*      ` ~ # & |    ^ { } [ ]      */
/*      ! _ : = $    @ ( ) _ ;      */
/*      % ? * + \    / - < > "      */

#define MIRYOKU_LAYER_SYM \
&kp GRAVE, &kp TILDE, &kp HASH,  &kp AMPS,  &kp PIPE,    &kp CARET, &kp LBRC,  &kp RBRC, &kp LBKT,  &kp RBKT,         \
U_MTR(LGUI, EXCL),  U_MTR(LALT, UNDER), U_MTR(LCTRL, COLON), U_MTR(LSHIFT, EQUAL), &kp DLLR,    &kp AT,    U_MTR(LSHIFT, LPAR), U_MTR(LCTRL, RPAR), U_MTR(LALT, UNDER), U_MTR(LGUI, SEMI),          \
&kp PRCNT, &kp QMARK, &kp ASTRK, &kp PLUS,  &kp BSLH,    &kp SLASH, &kp MINUS, &kp LT,   &kp GT,    &kp DQT,           \
U_NP,              U_NP,              &kp LPAR,          &kp RPAR,          &kp UNDER,         U_NA,              U_NA,              U_NA,              U_NP,              U_NP

