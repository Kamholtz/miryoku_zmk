// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_EYELASH_SOFLE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
/*  0 */  &kp ESC       /*  1   */  &kp N1       /*  2   */  &kp N2       /*  3   */  &kp N3       /*  4   */  &kp N4       /*  5   */  &kp N5       /*  6 */  &kp UP         /*  7   */  &kp N6       /*  8   */  &kp N7       /*  9   */  &kp N8       /* 10   */  &kp N9       /* 11   */  &kp N0       /* 12 */  &kp MINUS \
/* 13 */  &kp TAB       /* 14 Q */  K00          /* 15 W */  K01          /* 16 E */  K02          /* 17 R */  K03          /* 18 T */  K04          /* 19 */  &kp DOWN       /* 20 Y */  K05          /* 21 U */  K06          /* 22 I */  K07          /* 23 O */  K08          /* 24 P */  K09          /* 25 */  &kp BSLH \
/* 26 */  &kp LCTRL     /* 27 A */  K10          /* 28 S */  K11          /* 29 D */  K12          /* 30 F */  K13          /* 31 G */  K14          /* 32 */  &kp LEFT       /* 33 H */  K15          /* 34 J */  K16          /* 35 K */  K17          /* 36 L */  K18          /* 37 ; */  K19          /* 38 */  &kp SQT \
/* 39 */  &sk LSHFT     /* 40 Z */  K20          /* 41 X */  K21          /* 42 C */  K22          /* 43 V */  K23          /* 44 B */  K24          /* 45 */  &kp RIGHT      /* 46 N */  K25          /* 47 M */  K26          /* 48  */   K27          /* 49 . */  K28          /* 50 / */  K29          /* 51 */  &kp RET \
                        /* 52   */  XXX          /* 53   */  &kp LCTRL    /* 54   */  &kp LGUI     /* 55   */  K32          /* 56   */  K33          /* 57 */  K34            /* 58   */  &kp RET      /* 59   */  K35          /* 60   */  K36          /* 61   */  K37          /* 62   */  &sk RSHFT    /* 63 */  &kp RALT


// REFERENCE: zmk-docs/modifiers.md

#define MIRYOKU_LAYERMAPPING_NAV( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
/*  0 */  &kp ESC          /*  1   */  &kp LG(N1)   /*  2   */  &kp LG(N2)   /*  3   */  &kp LG(N3)   /*  4   */  &kp LG(N4)   /*  5   */  &kp LG(N5)   /*  6 */  &kp UP         /*  7   */  &kp LG(N6)   /*  8   */  &kp LG(N7)   /*  9   */  &kp LG(N8)   /* 10   */  &kp LG(N9)   /* 11   */  &kp LG(N0)   /* 12 */  &kp MINUS \
/* 13 */  &kp LG(LC(RIGHT))/* 14 Q */  K00          /* 15 W */  K01          /* 16 E */  K02          /* 17 R */  K03          /* 18 T */  K04          /* 19 */  &kp DOWN       /* 20 Y */  K05          /* 21 U */  K06          /* 22 I */  K07          /* 23 O */  K08          /* 24 P */  K09          /* 25 */  &kp BSLH \
/* 26 */  &kp LG(LC(LEFT)) /* 27 A */  K10          /* 28 S */  K11          /* 29 D */  K12          /* 30 F */  K13          /* 31 G */  K14          /* 32 */  &kp LEFT       /* 33 H */  K15          /* 34 J */  K16          /* 35 K */  K17          /* 36 L */  K18          /* 37 ; */  K19          /* 38 */  &kp SQT \
/* 39 */  &sk LSHFT        /* 40 Z */  K20          /* 41 X */  K21          /* 42 C */  K22          /* 43 V */  K23          /* 44 B */  K24          /* 45 */  &kp RIGHT      /* 46 N */  K25          /* 47 M */  K26          /* 48  */   K27          /* 49 . */  K28          /* 50 / */  K29          /* 51 */  &kp RET \
/* 52 */  XXX              /* 53   */  &kp LCTRL    /* 54   */  &kp LGUI     /* 55   */  K32          /* 56   */  K33          /* 57   */  K34          /* 58 */  &kp RET        /* 59   */  K35          /* 60   */  K36          /* 61   */  K37          /* 62   */  &sk RSHFT    /* 63   */  &kp RALT

#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      \
U_STU,             &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       &kp BSPC,          &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           &kp INS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

#define MIRYOKU_LAYERMAPPING_SYM( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39  \
) \
/*   0: `        1: [         2: (           3: )         4: ]        5: .             6: ↑            7: `          8: 7         9: 8        10: 9         11: 0         12: -      */ \
     &kp GRAVE  &kp LBKT     &kp LPAR       &kp RPAR     &kp RBKT    &kp DOT          &kp UP          &kp GRAVE     &kp LG(N7)   &kp LG(N8)   &kp LG(N9)    &kp LG(N0)    &kp MINUS \
/*  13: !       14: ,        15: {          16: }        17: ;       18: ?            19: ↓           20: "         21: @        22: :        23: O         24: P         25: \      */ \
     &kp EXCL   &kp COMMA    &kp LBRC       &kp RBRC     &kp SEMI    &kp QMARK        &kp DOWN        &kp DQT       &kp AT       &kp COLON    K08           K09           &kp BSLH \
/*  26: #       27: ^        28: =          29: _        30: $       31: *            32: ←          33: '         34: K        35: L        36: ;         37: K         38: '      */ \
    &kp HASH    &kp CARET    &kp EQUAL      &kp UNDER    &kp DLLR    &kp ASTRK        &kp LEFT        &kp SQT       K16          K17          K18           K19           &kp SQT \
/*  39: ~       40: <        41: |          42: -        43: >       44: /            45: →          46: \         47: %        48: +        49: &         50: K29       51: ⏎     */ \
    &kp TILDE   &kp LT       &kp PIPE       &kp MINUS    &kp GT      &kp SLASH        &kp RIGHT       &kp BSLH      &kp PRCNT    &kp PLUS     &kp AMPS      K29           &kp RET \
/*  52:         53: ⌃        54: ⌘          55:          56:         57:              58: ⏎          59:           60:          61:          62: ⇧         63: ⌥     */ \
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
        /* Q */           &kp Q,          /* W */           &kp W,          /* E */           &kp E,          /* R */           &kp R,          /* T */           &kp T,  /* Y */           &kp Y,          /* U */           &kp U,          /* I */           &kp I,          /* O */           &kp O,          /* P */           &kp P, \
        /* A */           &kp A,          /* S */           &kp S,          /* D */           &kp D,          /* F */           &kp F,          /* G */           &kp G,  /* H */           &kp H,          /* J */           &kp J,          /* K */           &kp K,          /* L */           &kp L,          /* ; */           &kp SEMI, \
        /* Z */           &kp Z,          /* X */           &kp X,          /* C */           &kp C,          /* V */           &kp V,          /* B */           &kp B,  /* N */           &kp N,          /* M */           &kp M,          /* , */           &kp COMMA,      /* . */           &kp DOT,        /* / */           &kp SLASH, \
        /*     */         U_NP,           /*     */         U_NP,           /* ESC */         &kp ESC,        /* SPACE */       &kp SPACE,      /* TAB */         &kp TAB,  /* RET */       &kp RET,        /* BSPC */        &kp BSPC,       /* DEL */         &kp DEL,        /*     */         U_NP,           /*     */         U_NP

// NOTE: comments for mod taps are wrong
#define MIRYOKU_LAYER_BASE \
        /* Q */           &kp Q,              /* W */              &kp W,              /* E */                &kp E,                /* R */                &kp R,              /* T */              &kp T,               /* Y */              &kp Y,              /* U */              &kp U,              /* I */                &kp I,                /* O */                &kp O,              /* P */              &kp P, \
        /* GUI+A */       U_MTL(LGUI, A),     /* ALT+S */          U_MTL(LALT, S),     /* CTRL+D */           U_MTL(LCTRL, D),      /* SHFT+F */           U_MTL(LSHFT, F),    /* G */              &kp G,               /* H */              &kp H,              /* SHFT+J */         U_MTR(LSHFT, J),    /* CTRL+K */           U_MTR(LCTRL, K),      /* ALT+L */            U_MTR(LALT, L),     /* GUI+; */          U_MTR(LGUI, SEMI), \
        /* Z (BTN) */     U_LT(U_BUTTON, Z),  /* RALT+X */         U_MTL(RALT, X),     /* C */                &kp C,                /* V */                &kp V,              /* B */              &kp B,               /* N */              &kp N,              /* M */              &kp M,              /* , */                &kp COMMA,            /* RALT+. */           U_MTR(RALT, DOT),   /* / (BTN) */        U_LT(U_BUTTON, SLASH), \
        /*     */         U_NP,               /*     */            U_NP,               /* ESC (MEDIA) */      U_LT(U_MEDIA, ESC),   /* SPACE (NAV) */      U_LT(U_NAV, SPACE), /* TAB (MOUSE) */    U_LT(U_MOUSE, TAB),  /* RET (SYM) */      U_LT(U_SYM, RET),   /* BSPC (NUM) */     U_LT(U_NUM, BSPC),  /* DEL (FUN) */        U_LT(U_FUN, DEL),     /*     */              U_NP,               /*     */            U_NP

#define MIRYOKU_LAYER_NUM \
        /*  0 [ */       &kp LBKT,           /*  1 7 */   &kp N7,    /*  2 8 */   &kp N8,      /*  3 9 */   &kp N9,      /*  4 ]  */   &kp RBKT,    /*| |*/   /*  5 */     U_NA,     /*  6 to BASE */    &u_to_U_BASE,      /*  7 to EXTRA */      &u_to_U_EXTRA,     /*  8 to TAP */       &u_to_U_TAP,       /*  9 BOOT */           U_BOOT, \
        /* 10 ; */       &kp SEMI,           /* 11 4 */   &kp N4,    /* 12 5 */   &kp N5,      /* 13 6 */   &kp N6,      /* 14 =  */   &kp EQUAL,   /*| |*/   /* 15 */     &kp BSPC, /* 16 LSHFT   */    &kp LSHFT,         /* 17 LCTRL    */      &kp LCTRL,         /* 18 LALT   */       &kp LALT,          /* 19 LGUI */           &kp LGUI, \
        /* 20 ` */       &kp GRAVE,          /* 21 1 */   &kp N1,    /* 22 2 */   &kp N2,      /* 23 3 */   &kp N3,      /* 24 \\ */   &kp BSLH,    /*| |*/   /* 25 */     U_NA,     /* 26 to NUM  */    &u_to_U_NUM,       /* 27 to NAV   */      &u_to_U_NAV,       /* 28 .      */       &kp DOT,           /* 29 /    */           &kp SLASH, \
        /* 30   */       U_NP,               /* 31   */   U_NP,      /* 32 . */   &kp DOT,     /* 33 0 */   &kp N0,      /* 34 -  */   &kp MINUS,   /*| |*/   /* 35 */     U_NA,     /* 36         */    U_NA,              /* 37          */      U_NA,              /* 38        */       U_NP,              /* 39      */           U_NP

/*https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/miryoku_for_programming/ */
/*      ` ~ # & |    ^ { } [ ]      */
/*      ! _ : = $    @ ( ) _ ;      */
/*      % ? * + \    / - < > "      */

#define MIRYOKU_LAYER_SYM \
        /* ` */             &kp GRAVE,          /* ~ */              &kp TILDE,             /* # */                &kp HASH,              /* & */             &kp AMPS,              /* | */             &kp PIPE,            /* ^ */             &kp CARET,          /* [ */              &kp LBRC,            /* ] */              &kp RBRC,             /* ⎡ */              &kp LBKT,           /* ⎤ */              &kp RBKT, \
        /* GUI+! */         U_MTL(LGUI, EXCL),  /* ALT+_ */          U_MTL(LALT, UNDER),    /* CTRL+: */           U_MTL(LCTRL, COLON),   /* SHFT+= */        U_MTL(LSHIFT, EQUAL),  /* $ */             &kp DLLR,            /* @ */             &kp AT,             /* (+SHFT) */        U_MTR(LSHIFT, LPAR), /* )+CTRL */         U_MTR(LCTRL, RPAR),   /* _+ALT */          U_MTR(LALT, UNDER), /* ;+GUI */          U_MTR(LGUI, SEMI), \
        /* % */             &kp PRCNT,          /* ? */              &kp QMARK,             /* * */                &kp ASTRK,             /* + */             &kp PLUS,              /* \\ */            &kp BSLH,            /* / */             &kp SLASH,          /* - */              &kp MINUS,           /* < */              &kp LT,               /* > */              &kp GT,             /* " */              &kp DQT, \
        /*     */           U_NP,               /*     */            U_NP,                  /* ( */                &kp LPAR,              /* ) */             &kp RPAR,              /* _ */             &kp UNDER,           /*     */           U_NA,               /*     */            U_NA,                /*     */            U_NA,                 /*     */            U_NP,               /*     */            U_NP


// test
