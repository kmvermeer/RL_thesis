/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * simulateDNA_data.c
 *
 * Code generation for function 'simulateDNA_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131434U, NULL, "simulateDNA",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

emlrtRSInfo x_emlrtRSI = { 13, "max",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

emlrtRSInfo y_emlrtRSI = { 19, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRSInfo ab_emlrtRSI = { 140, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRSInfo bb_emlrtRSI = { 375, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRSInfo cb_emlrtRSI = { 347, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRSInfo db_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

emlrtRSInfo jb_emlrtRSI = { 23, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

emlrtRSInfo kb_emlrtRSI = { 101, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

emlrtRSInfo lb_emlrtRSI = { 44, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

emlrtRSInfo mb_emlrtRSI = { 234, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

emlrtRSInfo nb_emlrtRSI = { 253, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

emlrtRSInfo dc_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ec_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo fc_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ud_emlrtRSI = { 12, "any",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\any.m" };

emlrtRSInfo vd_emlrtRSI = { 124, "allOrAny",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"
};

emlrtRSInfo wd_emlrtRSI = { 21, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo ee_emlrtRSI = { 42, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

emlrtRSInfo fe_emlrtRSI = { 101, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

emlrtRSInfo ge_emlrtRSI = { 99, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

emlrtRSInfo ne_emlrtRSI = { 18, "repmat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

emlrtRSInfo oe_emlrtRSI = { 45, "infocheck",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo pe_emlrtRSI = { 48, "infocheck",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"
};

emlrtRSInfo qe_emlrtRSI = { 241, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo re_emlrtRSI = { 268, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo we_emlrtRSI = { 76, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

emlrtRSInfo ye_emlrtRSI = { 28, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo af_emlrtRSI = { 32, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo bf_emlrtRSI = { 39, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo gf_emlrtRSI = { 12, "sqrt",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"
};

emlrtRSInfo jf_emlrtRSI = { 72, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo lf_emlrtRSI = { 79, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo mf_emlrtRSI = { 89, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

emlrtRSInfo nf_emlrtRSI = { 29, "xunormqr",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

emlrtRSInfo of_emlrtRSI = { 101, "xunormqr",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

emlrtRSInfo tf_emlrtRSI = { 14, "MGH_qq",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MGH_qq.m"
};

emlrtRSInfo vf_emlrtRSI = { 18, "MMH_qq",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMH_qq.m"
};

emlrtRSInfo wf_emlrtRSI = { 23, "MMH_qq",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMH_qq.m"
};

emlrtRSInfo xf_emlrtRSI = { 18, "MGP_qq",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MGP_qq.m"
};

emlrtRSInfo yf_emlrtRSI = { 18, "MGPm_qq",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MGPm_qq.m"
};

emlrtMCInfo emlrtMCI = { 27, 5, "error",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

emlrtRTEInfo p_emlrtRTEI = { 104, 1, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

emlrtRTEInfo lc_emlrtRTEI = { 243, 9, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

emlrtRTEInfo mc_emlrtRTEI = { 39, 27, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRTEInfo nc_emlrtRTEI = { 245, 27, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

emlrtRTEInfo oc_emlrtRTEI = { 121, 27, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

emlrtRTEInfo xc_emlrtRTEI = { 42, 19, "allOrAny",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"
};

emlrtRTEInfo yc_emlrtRTEI = { 39, 19, "allOrAny",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"
};

emlrtRTEInfo ad_emlrtRTEI = { 404, 15, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

emlrtRSInfo nh_emlrtRSI = { 27, "error",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

/* End of code generation (simulateDNA_data.c) */
