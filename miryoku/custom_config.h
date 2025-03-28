// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_EYELASH_SOFLE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
&kp ESC     &kp N1    &kp N2      &kp N3      &kp N4    &kp N5         &kp UP              &kp N6    &kp N7    &kp N8       &kp N9     &kp N0    &kp MINUS  \
&kp TAB     K00       K01         K02         K03       K04            &kp DOWN            K05       K06       K07          K08        K09       &kp BSLH  \
&kp LCTRL   K10       K11         K12         K13       K14            &kp LEFT            K15       K16       K17          K18        K19       &kp SQT   \
&sk LSHFT   K20       K21         K22         K23       K24            &kp RIGHT           K25       K26       K27          K28        K29       &kp RET   \
XXX                   &kp LCTRL   &kp LGUI    K32       K33     K34    &kp RET      K35    K36       K37       &sk RSHFT    &kp RALT

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
        /* Q */           &kp Q,          /* W */           &kp W,          /* E */           &kp E,          /* R */           &kp R,          /* T */           &kp T,  /* Y */           &kp Y,          /* U */           &kp U,          /* I */           &kp I,          /* O */           &kp O,          /* P */           &kp P, \
        /* A */           &kp A,          /* S */           &kp S,          /* D */           &kp D,          /* F */           &kp F,          /* G */           &kp G,  /* H */           &kp H,          /* J */           &kp J,          /* K */           &kp K,          /* L */           &kp L,          /* ; */           &kp SEMI, \
        /* Z */           &kp Z,          /* X */           &kp X,          /* C */           &kp C,          /* V */           &kp V,          /* B */           &kp B,  /* N */           &kp N,          /* M */           &kp M,          /* , */           &kp COMMA,      /* . */           &kp DOT,        /* / */           &kp SLASH, \
        /*     */         U_NP,           /*     */         U_NP,           /* ESC */         &kp ESC,        /* SPACE */       &kp SPACE,      /* TAB */         &kp TAB,  /* RET */       &kp RET,        /* BSPC */        &kp BSPC,       /* DEL */         &kp DEL,        /*     */         U_NP,           /*     */         U_NP

#define MIRYOKU_LAYER_BASE \
&kp Q,              &kp W,             &kp E,                &kp R,                 &kp T,                 &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
U_MTL(LGUI, A),     U_MTL(LALT, S),    U_MTL(LCTRL, D),      U_MTL(LSHFT, F),       &kp G,                 &kp H,             U_MTR(LSHFT, J),   U_MTR(LCTRL, K),   U_MTR(LALT, L),    U_MTR(LGUI, SEMI),   \
U_LT(U_BUTTON, Z),  U_MTL(RALT, X),    &kp C,                &kp V,                 &kp B,                 &kp N,             &kp M,             &kp COMMA,         U_MTR(RALT, DOT),  U_LT(U_BUTTON, SLASH),\
U_NP,               U_NP,              U_LT(U_MEDIA, ESC),   U_LT(U_NAV, SPACE),    U_LT(U_MOUSE, TAB),    U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

/*https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/miryoku_for_programming/ */
/*      ` ~ # & |    ^ { } [ ]      */
/*      ! _ : = $    @ ( ) _ ;      */
/*      % ? * + \    / - < > "      */

#define MIRYOKU_LAYER_SYM \
&kp GRAVE,          &kp TILDE,             &kp HASH,              &kp AMPS,             &kp PIPE,    &kp CARET,    &kp LBRC,               &kp RBRC,             &kp LBKT,           &kp RBKT,         \
U_MTL(LGUI, EXCL),  U_MTL(LALT, UNDER),    U_MTL(LCTRL, COLON),   U_MTL(LSHIFT, EQUAL), &kp DLLR,    &kp AT,       U_MTR(LSHIFT, LPAR),    U_MTR(LCTRL, RPAR),   U_MTR(LALT, UNDER), U_MTR(LGUI, SEMI),          \
&kp PRCNT,          &kp QMARK,             &kp ASTRK,             &kp PLUS,             &kp BSLH,    &kp SLASH,    &kp MINUS,              &kp LT,               &kp GT,             &kp DQT,           \
U_NP,               U_NP,                  &kp LPAR,              &kp RPAR,             &kp UNDER,   U_NA,         U_NA,                   U_NA,                 U_NP,               U_NP


