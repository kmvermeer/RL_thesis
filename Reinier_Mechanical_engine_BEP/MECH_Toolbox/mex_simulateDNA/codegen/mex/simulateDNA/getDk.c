/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getDk.c
 *
 * Code generation for function 'getDk'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getDk.h"
#include "MGPm_qq.h"
#include "MGP_qq.h"
#include "MMH_qq.h"
#include "MGH_qq.h"
#include "simulateDNA_emxutil.h"
#include "str2inc.h"
#include "MGH_q.h"
#include "MGH.h"
#include "MMH_q.h"
#include "MMH.h"
#include "any.h"
#include "indexShapeCheck.h"
#include "MGP_q.h"
#include "MGP.h"
#include "error.h"
#include "MGPm_q.h"
#include "MGPm.h"
#include "DNA2inc.h"
#include "sum.h"
#include "getCompoints.h"
#include "simulateDNA_mexutil.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xc_emlrtRSI = { 6, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo yc_emlrtRSI = { 10, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo ad_emlrtRSI = { 11, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo bd_emlrtRSI = { 12, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo cd_emlrtRSI = { 16, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo dd_emlrtRSI = { 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo ed_emlrtRSI = { 18, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo fd_emlrtRSI = { 30, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo gd_emlrtRSI = { 31, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo hd_emlrtRSI = { 36, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo id_emlrtRSI = { 38, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo jd_emlrtRSI = { 80, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo kd_emlrtRSI = { 82, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo ld_emlrtRSI = { 103, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo md_emlrtRSI = { 110, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo nd_emlrtRSI = { 112, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo od_emlrtRSI = { 126, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo pd_emlrtRSI = { 148, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo pf_emlrtRSI = { 51, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo qf_emlrtRSI = { 71, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo rf_emlrtRSI = { 97, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo sf_emlrtRSI = { 133, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo uf_emlrtRSI = { 49, "power",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo ig_emlrtRSI = { 142, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRSInfo jg_emlrtRSI = { 8, "MGPm_tt",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MGPm_tt.m"
};

static emlrtRTEInfo bb_emlrtRTEI = { 4, 34, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 6, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 16, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 17, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo fb_emlrtRTEI = { 18, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo gb_emlrtRTEI = { 30, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo hb_emlrtRTEI = { 126, 9, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtRTEInfo pb_emlrtRTEI = { 31, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtDCInfo f_emlrtDCI = { 23, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  4 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 30, 6, "state", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 30, 6, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  1 };

static emlrtDCInfo h_emlrtDCI = { 31, 6, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  1 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 31, 6, "state", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtRTEInfo bd_emlrtRTEI = { 35, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 36, 26, "incH", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 39, 15, "massnr", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 41, 24, "DNA.Hpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 42, 25, "comPoints", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 55, 16, "massnr", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 56, 16, "massnr", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 58, 24, "DNA.Hpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 59, 26, "comPoints", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 60, 26, "comPoints", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtRTEInfo cd_emlrtRTEI = { 79, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 80, 26, "incP", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 83, 15, "massnr", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 85, 26, "DNA.Ppar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 86, 28, "DNA.Ppar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 88, 25, "comPoints", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtRTEInfo dd_emlrtRTEI = { 109, 1, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 110, 27, "incPm", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 113, 15, "massnr", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 115, 33, "DNA.Pmpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 116, 31, "DNA.Pmpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 117, 31, "DNA.Pmpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 118, 31, "DNA.Pmpar", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 122, 29, "comPoints", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtECInfo k_emlrtECI = { -1, 128, 9, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo od_emlrtBCI = { -1, -1, 123, 19, "X", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 124, 19, "Xd", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 128, 11, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  1 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 128, 11, "D", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 89, 14, "X", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 90, 15, "Xd", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 92, 11, "D", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 61, 17, "X", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 61, 36, "X", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 62, 16, "Xd", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 62, 36, "Xd", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 64, 11, "D", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 43, 14, "X", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 44, 15, "Xd", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 46, 11, "D", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 94, 16, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtECInfo l_emlrtECI = { -1, 130, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo he_emlrtBCI = { -1, -1, 130, 20, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 130, 27, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 94, 20, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 67, 16, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 67, 26, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 68, 16, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 68, 26, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 48, 16, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 48, 26, "Dq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtECInfo m_emlrtECI = { -1, 136, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtECInfo n_emlrtECI = { -1, 133, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 133, 21, "Dqq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 136, 20, "Dt", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 97, 17, "Dqq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 71, 17, "Dqq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 51, 17, "Dqq", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtECInfo p_emlrtECI = { -1, 139, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtECInfo q_emlrtECI = { -1, 142, 17, "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m"
};

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 139, 21, "Dqt", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 142, 21, "Dtt", "getDk",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getDk.m",
  0 };

/* Function Definitions */
void b_getDk(const emlrtStack *sp, real_T t, const emxArray_real_T *state, const
             emxArray_real_T *DNA_incstr, const emxArray_real_T *DNA_edgelabel,
             const emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar,
             const emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
             const emxArray_real_T *DNA_Pmpar, emxArray_real_T *D,
             emxArray_real_T *Dq)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  boolean_T b2;
  boolean_T b3;
  int32_T i18;
  int32_T loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  real_T nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  real_T nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  real_T nPm;
  real_T nC;
  int32_T i19;
  real_T anew;
  emxArray_real_T *X;
  int32_T iv26[2];
  int32_T iv27[2];
  int32_T i20;
  real_T cnr;
  int32_T k;
  int32_T b_loop_ub;
  int32_T b_k;
  boolean_T x_data[100];
  int32_T idx;
  emxArray_real_T *cnrIdx;
  int32_T ii_data[100];
  emxArray_int32_T *r13;
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv28[2];
  int32_T massnr_data[100];
  boolean_T exitg1;
  boolean_T b_massnr_data[100];
  int32_T iv29[2];
  int32_T massnr_size[1];
  boolean_T guard1 = false;
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int32_T b_massnr_size[1];
  int32_T iv30[2];
  emxArray_boolean_T e_massnr_data;
  boolean_T f_massnr_data[100];
  int32_T i21;
  int32_T c_massnr_size[1];
  emxArray_boolean_T g_massnr_data;
  real_T mx[3];
  char_T u[78];
  static const char_T varargin_1[78] = { 'Y', 'o', 'u', ' ', 'c', 'a', 'n', ' ',
    'o', 'n', 'l', 'y', ' ', 'u', 's', 'e', ' ', 'e', 'd', 'g', 'e', ' ', '3',
    ',', ' ', 'i', '.', 'e', '.', ' ', 'p', 'e', 'n', 'd', 'u', 'l', 'u', 'm',
    ' ', 'o', 'n', ' ', 'c', 'a', 'r', 't', ',', ' ', 'i', 'f', ' ', 'i', 't',
    ' ', 'i', 's', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', 't',
    'o', ' ', 'a', ' ', 'g', 'r', 'o', 'u', 'n', 'd' };

  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv31[2] = { 1, 78 };

  real_T ndbl;
  real_T b_X[6];
  real_T b_comPoints[2];
  real_T dv3[2];
  real_T b_mx[6];
  int32_T b_Dq;
  real_T c_comPoints[2];
  real_T dv4[3];
  real_T MMHconstraintd[12];
  real_T apnd;
  boolean_T n_too_large;
  real_T cdiff;
  int32_T iv32[1];
  int32_T iv33[2];
  int32_T iv34[3];
  int32_T iv35[2];
  int32_T iv36[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &comPoints, 2, &cb_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  b2 = false;
  b3 = false;
  st.site = &xc_emlrtRSI;
  getCompoints(&st, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
               DNA_Ppar, DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i18 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i18, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i18 = 0; i18 < loop_ub; i18++) {
    b_DNA_edgelabel->data[i18] = (DNA_edgelabel->data[i18] == 1.0);
  }

  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &yc_emlrtRSI;
  nH = sum(&st, b_DNA_edgelabel);

  /* Number of hinges */
  i18 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i18, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i18 = 0; i18 < loop_ub; i18++) {
    c_DNA_edgelabel->data[i18] = (DNA_edgelabel->data[i18] == 3.0);
  }

  emxInit_boolean_T(sp, &d_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &ad_emlrtRSI;
  nP = sum(&st, c_DNA_edgelabel);
  i18 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_DNA_edgelabel, i18, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i18 = 0; i18 < loop_ub; i18++) {
    d_DNA_edgelabel->data[i18] = (DNA_edgelabel->data[i18] == 4.0);
  }

  emxInit_real_T(sp, &incH, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &incP, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &incPm, 2, &fb_emlrtRTEI, true);
  st.site = &bd_emlrtRSI;
  nPm = sum(&st, d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  st.site = &cd_emlrtRSI;
  b_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  st.site = &dd_emlrtRSI;
  c_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incP);
  st.site = &ed_emlrtRSI;
  d_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i18 = D->size[0];
  D->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)D, i18, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i18 = 0; i18 < loop_ub; i18++) {
    D->data[i18] = 0.0;
  }

  /* For scleronomic constraints */
  i18 = DNA_Mpar->size[0];
  i19 = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int32_T)nC;
  anew = ((real_T)i18 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  Dq->size[1] = (int32_T)anew;
  emxEnsureCapacity(sp, (emxArray__common *)Dq, i19, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  anew = ((real_T)i18 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nC * (int32_T)anew;
  for (i18 = 0; i18 < loop_ub; i18++) {
    Dq->data[i18] = 0.0;
  }

  /* Extra for rheonomic constraints */
  anew = (real_T)state->size[0] / 2.0;
  if (1.0 > anew) {
    loop_ub = 0;
  } else {
    i18 = state->size[0];
    if (!(1 <= i18)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i18, &qc_emlrtBCI, sp);
    }

    if (anew != muDoubleScalarFloor(anew)) {
      emlrtIntegerCheckR2012b(anew, &g_emlrtDCI, sp);
    }

    i18 = state->size[0];
    loop_ub = (int32_T)anew;
    if (!(loop_ub <= i18)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, &qc_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &X, 2, &gb_emlrtRTEI, true);
  iv26[0] = 1;
  iv26[1] = loop_ub;
  st.site = &fd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv26);
  i18 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)X, i18, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (i18 = 0; i18 < loop_ub; i18++) {
    X->data[X->size[0] * i18] = state->data[i18];
  }

  anew = (real_T)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i19 = 1;
    i18 = 1;
  } else {
    if (anew + 1.0 != muDoubleScalarFloor(anew + 1.0)) {
      emlrtIntegerCheckR2012b(anew + 1.0, &h_emlrtDCI, sp);
    }

    i18 = state->size[0];
    i19 = (int32_T)(anew + 1.0);
    if (!((i19 >= 1) && (i19 <= i18))) {
      emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &rc_emlrtBCI, sp);
    }

    i18 = state->size[0];
    i20 = state->size[0];
    if (!((i20 >= 1) && (i20 <= i18))) {
      emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &rc_emlrtBCI, sp);
    }

    i18 = i20 + 1;
  }

  iv27[0] = 1;
  iv27[1] = i18 - i19;
  st.site = &gd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv27);

  /* For rotational joint */
  cnr = 1.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nH, mxDOUBLE_CLASS, (int32_T)nH,
    &bd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nH - 1) {
    st.site = &hd_emlrtRSI;
    b_loop_ub = incH->size[0];
    i20 = incH->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i20))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i20, &sc_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      x_data[i20] = (incH->data[i20 + incH->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= b_loop_ub)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i20 = 0;
      } else {
        i20 = idx;
      }

      iv28[0] = 1;
      iv28[1] = i20;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv28);
      b_loop_ub = i20;
    }

    for (i20 = 0; i20 < b_loop_ub; i20++) {
      massnr_data[i20] = ii_data[i20];
    }

    /* Find entries in column */
    massnr_size[0] = b_loop_ub;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      b_massnr_data[i20] = (massnr_data[i20] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int32_T *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    st.site = &id_emlrtRSI;
    if (any(&st, &c_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &tc_emlrtBCI, sp);
      }

      i20 = DNA_Hpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &uc_emlrtBCI, sp);
      }

      i20 = comPoints->size[0];
      i21 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &vc_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, loop_ub, &ae_emlrtBCI, sp);
        }

        mx[i20] = X->data[i21 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i18 - i19;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &be_emlrtBCI, sp);
        }
      }

      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MGH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, dv3);
      idx = D->size[0];
      for (i20 = 0; i20 < 2; i20++) {
        i21 = (int32_T)(cnr + (real_T)i20);
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &ce_emlrtBCI, sp);
        }

        D->data[i21 - 1] = dv3[i20];
      }

      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MGH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i20 = 0; i20 < 3; i20++) {
        for (i21 = 0; i21 < 2; i21++) {
          ii = (int32_T)(cnr + (real_T)i21);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &oe_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i20));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &pe_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = b_X[i21 + (i20 << 1)];
        }
      }

      cnr += 2.0;
    } else {
      if (!(1 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_loop_ub, &wc_emlrtBCI, sp);
      }

      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &xc_emlrtBCI, sp);
      }

      i20 = DNA_Hpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &yc_emlrtBCI, sp);
      }

      i20 = comPoints->size[0];
      i21 = (int32_T)((real_T)massnr_data[0] - 1.0);
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &ad_emlrtBCI, sp);
      }

      i20 = comPoints->size[0];
      i21 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &bd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, loop_ub, &ud_emlrtBCI, sp);
        }

        b_X[i20] = X->data[i21 - 1];
      }

      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(ndbl + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, loop_ub, &vd_emlrtBCI, sp);
        }

        b_X[i20 + 3] = X->data[i21 - 1];
      }

      for (i20 = 0; i20 < 6; i20++) {
        b_mx[i20] = b_X[i20];
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = i18 - i19;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &wd_emlrtBCI, sp);
        }
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i18 - i19;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &xd_emlrtBCI, sp);
        }
      }

      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      for (i20 = 0; i20 < 2; i20++) {
        c_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MMH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, dv3);
      idx = D->size[0];
      for (i20 = 0; i20 < 2; i20++) {
        i21 = (int32_T)(cnr + (real_T)i20);
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &yd_emlrtBCI, sp);
        }

        D->data[i21 - 1] = dv3[i20];
      }

      /* Constraints */
      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      for (i20 = 0; i20 < 2; i20++) {
        c_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MMH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i20 = 0; i20 < 3; i20++) {
        for (i21 = 0; i21 < 2; i21++) {
          ii = (int32_T)(cnr + (real_T)i21);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &ke_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i20));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &le_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i21 +
            (i20 << 1)];
        }
      }

      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i20 = 0; i20 < 3; i20++) {
        for (i21 = 0; i21 < 2; i21++) {
          ii = (int32_T)(cnr + (real_T)i21);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &me_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i20));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &ne_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i21 +
            ((3 + i20) << 1)];
        }
      }

      cnr += 2.0;
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nP, mxDOUBLE_CLASS, (int32_T)nP,
    &cd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nP - 1) {
    st.site = &jd_emlrtRSI;
    b_loop_ub = incP->size[0];
    i20 = incP->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i20))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i20, &cd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      x_data[i20] = (incP->data[i20 + incP->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= b_loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i20 = 0;
      } else {
        i20 = idx;
      }

      iv29[0] = 1;
      iv29[1] = i20;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv29);
      b_loop_ub = i20;
    }

    for (i20 = 0; i20 < b_loop_ub; i20++) {
      massnr_data[i20] = ii_data[i20];
    }

    /* Find entries in column */
    b_massnr_size[0] = b_loop_ub;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      d_massnr_data[i20] = (massnr_data[i20] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int32_T *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    st.site = &kd_emlrtRSI;
    if (any(&st, &e_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &dd_emlrtBCI, sp);
      }

      i20 = DNA_Ppar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &ed_emlrtBCI, sp);
      }

      i20 = DNA_Ppar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &fd_emlrtBCI, sp);
      }

      i20 = comPoints->size[0];
      i21 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &gd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, loop_ub, &rd_emlrtBCI, sp);
        }

        mx[i20] = X->data[i21 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i18 - i19;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &sd_emlrtBCI, sp);
        }
      }

      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      i20 = D->size[0];
      i21 = (int32_T)cnr;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &td_emlrtBCI, sp);
      }

      D->data[i21 - 1] = MGP(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] *
        k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MGP_q(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv4);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      i20 = (int32_T)cnr;
      if (!((i20 >= 1) && (i20 <= b_Dq))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, b_Dq, &ge_emlrtBCI, sp);
      }

      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &je_emlrtBCI, sp);
        }

        Dq->data[((int32_T)cnr + Dq->size[0] * (i21 - 1)) - 1] = dv4[i20];
      }

      cnr++;
    } else {
      st.site = &ld_emlrtRSI;
      error(&st);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nPm, mxDOUBLE_CLASS, (int32_T)nPm,
    &dd_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T(sp, &cnrIdx, 2, &hb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r13, 1, &bb_emlrtRTEI, true);
  while (k <= (int32_T)nPm - 1) {
    st.site = &md_emlrtRSI;
    b_loop_ub = incPm->size[0];
    i20 = incPm->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i20))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i20, &hd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      x_data[i20] = (incPm->data[i20 + incPm->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= b_loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i20 = 0;
      } else {
        i20 = idx;
      }

      iv30[0] = 1;
      iv30[1] = i20;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv30);
      b_loop_ub = i20;
    }

    for (i20 = 0; i20 < b_loop_ub; i20++) {
      massnr_data[i20] = ii_data[i20];
    }

    /* Find entries in column */
    c_massnr_size[0] = b_loop_ub;
    for (i20 = 0; i20 < b_loop_ub; i20++) {
      f_massnr_data[i20] = (massnr_data[i20] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int32_T *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    st.site = &nd_emlrtRSI;
    if (any(&st, &g_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &id_emlrtBCI, sp);
      }

      i20 = DNA_Pmpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &jd_emlrtBCI, sp);
      }

      i20 = DNA_Pmpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &kd_emlrtBCI, sp);
      }

      i20 = DNA_Pmpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &ld_emlrtBCI, sp);
      }

      i20 = DNA_Pmpar->size[1];
      i21 = k + 1;
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &md_emlrtBCI, sp);
      }

      /*          keyboard  */
      i20 = comPoints->size[0];
      i21 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i21 >= 1) && (i21 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i20, &nd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, loop_ub, &od_emlrtBCI, sp);
        }

        mx[i20] = X->data[i21 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i18 - i19;
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &pd_emlrtBCI, sp);
        }
      }

      st.site = &od_emlrtRSI;
      b_st.site = &wd_emlrtRSI;
      c_st.site = &dc_emlrtRSI;
      if (cnr + 1.0 < cnr) {
        ii = 0;
        anew = cnr;
        apnd = cnr + 1.0;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(cnr) || muDoubleScalarIsInf(cnr + 1.0)) {
        ii = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
        n_too_large = !(cnr == cnr + 1.0);
      } else {
        anew = cnr;
        ndbl = muDoubleScalarFloor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
            muDoubleScalarMax(cnr, cnr + 1.0)) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n_too_large = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          ii = (int32_T)ndbl;
        } else {
          ii = 0;
        }
      }

      d_st.site = &ec_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &ad_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i20 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = ii;
      emxEnsureCapacity(&c_st, (emxArray__common *)cnrIdx, i20, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      if (ii > 0) {
        cnrIdx->data[0] = anew;
        if (ii > 1) {
          cnrIdx->data[ii - 1] = apnd;
          idx = (ii - 1) / 2;
          d_st.site = &fc_emlrtRSI;
          for (b_k = 1; b_k < idx; b_k++) {
            cnrIdx->data[b_k] = anew + (real_T)b_k;
            cnrIdx->data[(ii - b_k) - 1] = apnd - (real_T)b_k;
          }

          if (idx << 1 == ii - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (real_T)idx;
            cnrIdx->data[idx + 1] = apnd - (real_T)idx;
          }
        }
      }

      /*           keyboard  */
      idx = D->size[0];
      i20 = r13->size[0];
      r13->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r13, i20, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i20 = 0; i20 < b_loop_ub; i20++) {
        anew = cnrIdx->data[cnrIdx->size[0] * i20];
        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
        }

        i21 = (int32_T)anew;
        if (!((i21 >= 1) && (i21 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, idx, &qd_emlrtBCI, sp);
        }

        r13->data[i20] = i21 - 1;
      }

      iv32[0] = r13->size[0];
      if (!b2) {
        for (i20 = 0; i20 < 2; i20++) {
          iv33[i20] = 1 + i20;
        }

        b2 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv32, 1, iv33, 2, &k_emlrtECI, sp);
      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MGPm(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, dv3);
      idx = r13->size[0];
      for (i20 = 0; i20 < idx; i20++) {
        D->data[r13->data[i20]] = dv3[i20];
      }

      b_Dq = Dq->size[0];
      i20 = r13->size[0];
      r13->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r13, i20, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i20 = 0; i20 < b_loop_ub; i20++) {
        i21 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i20];
        if (!((i21 >= 1) && (i21 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, b_Dq, &he_emlrtBCI, sp);
        }

        r13->data[i20] = i21 - 1;
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      b_Dq = Dq->size[1];
      for (i20 = 0; i20 < 3; i20++) {
        i21 = (int32_T)(anew + (-2.0 + (real_T)i20));
        if (!((i21 >= 1) && (i21 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i21, 1, b_Dq, &ie_emlrtBCI, sp);
        }

        iv34[i20] = i21 - 1;
      }

      iv35[0] = r13->size[0];
      iv35[1] = 3;
      if (!b3) {
        for (i20 = 0; i20 < 2; i20++) {
          iv36[i20] = 2 + i20;
        }

        b3 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv35, 2, iv36, 2, &l_emlrtECI, sp);
      for (i20 = 0; i20 < 2; i20++) {
        b_comPoints[i20] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i20) - 1];
      }

      MGPm_q(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      idx = r13->size[0];
      for (i20 = 0; i20 < 3; i20++) {
        for (i21 = 0; i21 < idx; i21++) {
          Dq->data[r13->data[i21] + Dq->size[0] * iv34[i20]] = b_X[i21 + idx *
            i20];
        }
      }

      /*  keyboard  */
      cnr += 2.0;
    } else {
      st.site = &pd_emlrtRSI;
      memcpy(&u[0], &varargin_1[0], 78U * sizeof(char_T));
      y = NULL;
      m3 = emlrtCreateCharArray(2, iv31);
      emlrtInitCharArrayR2013a(&st, 78, m3, &u[0]);
      emlrtAssign(&y, m3);
      b_st.site = &nh_emlrtRSI;
      g_error(&b_st, y, &emlrtMCI);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r13);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_getDk(const emlrtStack *sp, real_T t, const emxArray_real_T *state, const
             emxArray_real_T *DNA_incstr, const emxArray_real_T *DNA_edgelabel,
             const emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar,
             const emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
             const emxArray_real_T *DNA_Pmpar, emxArray_real_T *D,
             emxArray_real_T *Dq, emxArray_real_T *Dqq, emxArray_real_T *Dt)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  boolean_T b4;
  boolean_T b5;
  boolean_T b6;
  boolean_T b7;
  int32_T i26;
  int32_T loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  real_T nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  real_T nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  real_T nPm;
  real_T nC;
  int32_T i27;
  real_T anew;
  emxArray_real_T *X;
  int32_T iv45[2];
  emxArray_real_T *Xd;
  int32_T iv46[2];
  int32_T i28;
  int32_T b_loop_ub;
  real_T cnr;
  int32_T k;
  int32_T b_k;
  boolean_T x_data[100];
  int32_T idx;
  emxArray_real_T *cnrIdx;
  int32_T ii_data[100];
  emxArray_int32_T *r14;
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv47[2];
  int32_T massnr_data[100];
  boolean_T exitg1;
  boolean_T b_massnr_data[100];
  int32_T iv48[2];
  int32_T massnr_size[1];
  boolean_T guard1 = false;
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int32_T b_massnr_size[1];
  int32_T iv49[2];
  emxArray_boolean_T e_massnr_data;
  boolean_T f_massnr_data[100];
  int32_T i29;
  int32_T c_massnr_size[1];
  emxArray_boolean_T g_massnr_data;
  real_T mx[3];
  char_T u[78];
  static const char_T varargin_1[78] = { 'Y', 'o', 'u', ' ', 'c', 'a', 'n', ' ',
    'o', 'n', 'l', 'y', ' ', 'u', 's', 'e', ' ', 'e', 'd', 'g', 'e', ' ', '3',
    ',', ' ', 'i', '.', 'e', '.', ' ', 'p', 'e', 'n', 'd', 'u', 'l', 'u', 'm',
    ' ', 'o', 'n', ' ', 'c', 'a', 'r', 't', ',', ' ', 'i', 'f', ' ', 'i', 't',
    ' ', 'i', 's', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', 't',
    'o', ' ', 'a', ' ', 'g', 'r', 'o', 'u', 'n', 'd' };

  const mxArray *y;
  const mxArray *m7;
  static const int32_T iv50[2] = { 1, 78 };

  real_T ndbl;
  real_T mxd[3];
  real_T b_X[6];
  real_T b_comPoints[2];
  real_T b_mx[6];
  real_T dv5[2];
  int32_T b_Dq;
  real_T b_mxd[6];
  real_T dv6[3];
  real_T c_comPoints[2];
  real_T apnd;
  boolean_T n_too_large;
  real_T cdiff;
  real_T MMHconstraintd[12];
  int32_T iv51[1];
  int32_T iv52[2];
  int32_T iv53[3];
  int32_T iv54[2];
  int32_T iv55[2];
  int32_T iv56[1];
  int32_T iv57[1];
  int32_T iv58[1];
  int32_T iv59[1];
  real_T dv7[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &comPoints, 2, &cb_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  b4 = false;
  b5 = false;
  b6 = false;
  b7 = false;
  st.site = &xc_emlrtRSI;
  getCompoints(&st, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
               DNA_Ppar, DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i26 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i26, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i26 = 0; i26 < loop_ub; i26++) {
    b_DNA_edgelabel->data[i26] = (DNA_edgelabel->data[i26] == 1.0);
  }

  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &yc_emlrtRSI;
  nH = sum(&st, b_DNA_edgelabel);

  /* Number of hinges */
  i26 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i26, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i26 = 0; i26 < loop_ub; i26++) {
    c_DNA_edgelabel->data[i26] = (DNA_edgelabel->data[i26] == 3.0);
  }

  emxInit_boolean_T(sp, &d_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &ad_emlrtRSI;
  nP = sum(&st, c_DNA_edgelabel);
  i26 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_DNA_edgelabel, i26, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i26 = 0; i26 < loop_ub; i26++) {
    d_DNA_edgelabel->data[i26] = (DNA_edgelabel->data[i26] == 4.0);
  }

  emxInit_real_T(sp, &incH, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &incP, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &incPm, 2, &fb_emlrtRTEI, true);
  st.site = &bd_emlrtRSI;
  nPm = sum(&st, d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  st.site = &cd_emlrtRSI;
  b_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  st.site = &dd_emlrtRSI;
  c_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incP);
  st.site = &ed_emlrtRSI;
  d_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i26 = D->size[0];
  D->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)D, i26, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i26 = 0; i26 < loop_ub; i26++) {
    D->data[i26] = 0.0;
  }

  /* For scleronomic constraints */
  i26 = DNA_Mpar->size[0];
  i27 = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int32_T)nC;
  anew = ((real_T)i26 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  Dq->size[1] = (int32_T)anew;
  emxEnsureCapacity(sp, (emxArray__common *)Dq, i27, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  anew = ((real_T)i26 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nC * (int32_T)anew;
  for (i26 = 0; i26 < loop_ub; i26++) {
    Dq->data[i26] = 0.0;
  }

  i26 = Dqq->size[0];
  Dqq->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dqq, i26, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i26 = 0; i26 < loop_ub; i26++) {
    Dqq->data[i26] = 0.0;
  }

  i26 = Dt->size[0];
  Dt->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dt, i26, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i26 = 0; i26 < loop_ub; i26++) {
    Dt->data[i26] = 0.0;
  }

  /* Extra for rheonomic constraints */
  anew = (real_T)state->size[0] / 2.0;
  if (1.0 > anew) {
    loop_ub = 0;
  } else {
    i26 = state->size[0];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &qc_emlrtBCI, sp);
    }

    if (anew != muDoubleScalarFloor(anew)) {
      emlrtIntegerCheckR2012b(anew, &g_emlrtDCI, sp);
    }

    i26 = state->size[0];
    loop_ub = (int32_T)anew;
    if (!(loop_ub <= i26)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &qc_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &X, 2, &gb_emlrtRTEI, true);
  iv45[0] = 1;
  iv45[1] = loop_ub;
  st.site = &fd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv45);
  i26 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)X, i26, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (i26 = 0; i26 < loop_ub; i26++) {
    X->data[X->size[0] * i26] = state->data[i26];
  }

  anew = (real_T)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i27 = 1;
    i26 = 1;
  } else {
    if (anew + 1.0 != muDoubleScalarFloor(anew + 1.0)) {
      emlrtIntegerCheckR2012b(anew + 1.0, &h_emlrtDCI, sp);
    }

    i26 = state->size[0];
    i27 = (int32_T)(anew + 1.0);
    if (!((i27 >= 1) && (i27 <= i26))) {
      emlrtDynamicBoundsCheckR2012b(i27, 1, i26, &rc_emlrtBCI, sp);
    }

    i26 = state->size[0];
    i28 = state->size[0];
    if (!((i28 >= 1) && (i28 <= i26))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, i26, &rc_emlrtBCI, sp);
    }

    i26 = i28 + 1;
  }

  emxInit_real_T(sp, &Xd, 2, &pb_emlrtRTEI, true);
  iv46[0] = 1;
  iv46[1] = i26 - i27;
  st.site = &gd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv46);
  i28 = Xd->size[0] * Xd->size[1];
  Xd->size[0] = 1;
  Xd->size[1] = i26 - i27;
  emxEnsureCapacity(sp, (emxArray__common *)Xd, i28, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  b_loop_ub = i26 - i27;
  for (i28 = 0; i28 < b_loop_ub; i28++) {
    Xd->data[Xd->size[0] * i28] = state->data[(i27 + i28) - 1];
  }

  /* For rotational joint */
  cnr = 1.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nH, mxDOUBLE_CLASS, (int32_T)nH,
    &bd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nH - 1) {
    st.site = &hd_emlrtRSI;
    b_loop_ub = incH->size[0];
    i28 = incH->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i28, &sc_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      x_data[i28] = (incH->data[i28 + incH->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= b_loop_ub)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i28 = 0;
      } else {
        i28 = idx;
      }

      iv47[0] = 1;
      iv47[1] = i28;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv47);
      b_loop_ub = i28;
    }

    for (i28 = 0; i28 < b_loop_ub; i28++) {
      massnr_data[i28] = ii_data[i28];
    }

    /* Find entries in column */
    massnr_size[0] = b_loop_ub;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      b_massnr_data[i28] = (massnr_data[i28] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int32_T *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    st.site = &id_emlrtRSI;
    if (any(&st, &c_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &tc_emlrtBCI, sp);
      }

      i28 = DNA_Hpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &uc_emlrtBCI, sp);
      }

      i28 = comPoints->size[0];
      i29 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &vc_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, loop_ub, &ae_emlrtBCI, sp);
        }

        mx[i28] = X->data[i29 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i26 - i27;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &be_emlrtBCI, sp);
        }

        mxd[i28] = Xd->data[i29 - 1];
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MGH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, dv5);
      idx = D->size[0];
      for (i28 = 0; i28 < 2; i28++) {
        i29 = (int32_T)(cnr + (real_T)i28);
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &ce_emlrtBCI, sp);
        }

        D->data[i29 - 1] = dv5[i28];
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MGH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i28 = 0; i28 < 3; i28++) {
        for (i29 = 0; i29 < 2; i29++) {
          ii = (int32_T)(cnr + (real_T)i29);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &oe_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i28));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &pe_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = b_X[i29 + (i28 << 1)];
        }
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      st.site = &pf_emlrtRSI;
      MGH_qq(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             mx, mxd, dv5);
      idx = Dqq->size[0];
      for (i28 = 0; i28 < 2; i28++) {
        i29 = (int32_T)(cnr + (real_T)i28);
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &ue_emlrtBCI, sp);
        }

        Dqq->data[i29 - 1] = dv5[i28];
      }

      cnr += 2.0;
    } else {
      if (!(1 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_loop_ub, &wc_emlrtBCI, sp);
      }

      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &xc_emlrtBCI, sp);
      }

      i28 = DNA_Hpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &yc_emlrtBCI, sp);
      }

      i28 = comPoints->size[0];
      i29 = (int32_T)((real_T)massnr_data[0] - 1.0);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &ad_emlrtBCI, sp);
      }

      i28 = comPoints->size[0];
      i29 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &bd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, loop_ub, &ud_emlrtBCI, sp);
        }

        b_X[i28] = X->data[i29 - 1];
      }

      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(ndbl + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, loop_ub, &vd_emlrtBCI, sp);
        }

        b_X[i28 + 3] = X->data[i29 - 1];
      }

      for (i28 = 0; i28 < 6; i28++) {
        b_mx[i28] = b_X[i28];
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = i26 - i27;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = i26 - i27;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &wd_emlrtBCI, sp);
        }

        b_X[i28] = Xd->data[i29 - 1];
      }

      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(ndbl + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, ii, &xd_emlrtBCI, sp);
        }

        b_X[i28 + 3] = Xd->data[i29 - 1];
      }

      for (i28 = 0; i28 < 6; i28++) {
        b_mxd[i28] = b_X[i28];
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      for (i28 = 0; i28 < 2; i28++) {
        c_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MMH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, dv5);
      idx = D->size[0];
      for (i28 = 0; i28 < 2; i28++) {
        i29 = (int32_T)(cnr + (real_T)i28);
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &yd_emlrtBCI, sp);
        }

        D->data[i29 - 1] = dv5[i28];
      }

      /* Constraints */
      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      for (i28 = 0; i28 < 2; i28++) {
        c_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MMH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i28 = 0; i28 < 3; i28++) {
        for (i29 = 0; i29 < 2; i29++) {
          ii = (int32_T)(cnr + (real_T)i29);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &ke_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i28));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &le_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i29 +
            (i28 << 1)];
        }
      }

      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i28 = 0; i28 < 3; i28++) {
        for (i29 = 0; i29 < 2; i29++) {
          ii = (int32_T)(cnr + (real_T)i29);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &me_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i28));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &ne_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i29 +
            ((3 + i28) << 1)];
        }
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      for (i28 = 0; i28 < 2; i28++) {
        c_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      st.site = &qf_emlrtRSI;
      MMH_qq(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             c_comPoints, b_mx, b_mxd, dv5);
      idx = Dqq->size[0];
      for (i28 = 0; i28 < 2; i28++) {
        i29 = (int32_T)(cnr + (real_T)i28);
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &te_emlrtBCI, sp);
        }

        Dqq->data[i29 - 1] = dv5[i28];
      }

      /* Double derivative of constraints */
      cnr += 2.0;
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nP, mxDOUBLE_CLASS, (int32_T)nP,
    &cd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nP - 1) {
    st.site = &jd_emlrtRSI;
    b_loop_ub = incP->size[0];
    i28 = incP->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i28, &cd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      x_data[i28] = (incP->data[i28 + incP->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= b_loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i28 = 0;
      } else {
        i28 = idx;
      }

      iv48[0] = 1;
      iv48[1] = i28;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv48);
      b_loop_ub = i28;
    }

    for (i28 = 0; i28 < b_loop_ub; i28++) {
      massnr_data[i28] = ii_data[i28];
    }

    /* Find entries in column */
    b_massnr_size[0] = b_loop_ub;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      d_massnr_data[i28] = (massnr_data[i28] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int32_T *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    st.site = &kd_emlrtRSI;
    if (any(&st, &e_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &dd_emlrtBCI, sp);
      }

      i28 = DNA_Ppar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &ed_emlrtBCI, sp);
      }

      i28 = DNA_Ppar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &fd_emlrtBCI, sp);
      }

      i28 = comPoints->size[0];
      i29 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &gd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, loop_ub, &rd_emlrtBCI, sp);
        }

        mx[i28] = X->data[i29 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i26 - i27;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &sd_emlrtBCI, sp);
        }

        mxd[i28] = Xd->data[i29 - 1];
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      i28 = D->size[0];
      i29 = (int32_T)cnr;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &td_emlrtBCI, sp);
      }

      D->data[i29 - 1] = MGP(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] *
        k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MGP_q(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv6);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      i28 = (int32_T)cnr;
      if (!((i28 >= 1) && (i28 <= b_Dq))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, b_Dq, &ge_emlrtBCI, sp);
      }

      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &je_emlrtBCI, sp);
        }

        Dq->data[((int32_T)cnr + Dq->size[0] * (i29 - 1)) - 1] = dv6[i28];
      }

      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      i28 = Dqq->size[0];
      i29 = (int32_T)cnr;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &se_emlrtBCI, sp);
      }

      st.site = &rf_emlrtRSI;
      Dqq->data[i29 - 1] = MGP_qq(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx,
        mxd);
      cnr++;
    } else {
      st.site = &ld_emlrtRSI;
      error(&st);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nPm, mxDOUBLE_CLASS, (int32_T)nPm,
    &dd_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T(sp, &cnrIdx, 2, &hb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r14, 1, &bb_emlrtRTEI, true);
  while (k <= (int32_T)nPm - 1) {
    st.site = &md_emlrtRSI;
    b_loop_ub = incPm->size[0];
    i28 = incPm->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i28, &hd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      x_data[i28] = (incPm->data[i28 + incPm->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= b_loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i28 = 0;
      } else {
        i28 = idx;
      }

      iv49[0] = 1;
      iv49[1] = i28;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv49);
      b_loop_ub = i28;
    }

    for (i28 = 0; i28 < b_loop_ub; i28++) {
      massnr_data[i28] = ii_data[i28];
    }

    /* Find entries in column */
    c_massnr_size[0] = b_loop_ub;
    for (i28 = 0; i28 < b_loop_ub; i28++) {
      f_massnr_data[i28] = (massnr_data[i28] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int32_T *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    st.site = &nd_emlrtRSI;
    if (any(&st, &g_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &id_emlrtBCI, sp);
      }

      i28 = DNA_Pmpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &jd_emlrtBCI, sp);
      }

      i28 = DNA_Pmpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &kd_emlrtBCI, sp);
      }

      i28 = DNA_Pmpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &ld_emlrtBCI, sp);
      }

      i28 = DNA_Pmpar->size[1];
      i29 = k + 1;
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &md_emlrtBCI, sp);
      }

      /*          keyboard  */
      i28 = comPoints->size[0];
      i29 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, &nd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, loop_ub, &od_emlrtBCI, sp);
        }

        mx[i28] = X->data[i29 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i26 - i27;
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &pd_emlrtBCI, sp);
        }

        mxd[i28] = Xd->data[i29 - 1];
      }

      st.site = &od_emlrtRSI;
      b_st.site = &wd_emlrtRSI;
      c_st.site = &dc_emlrtRSI;
      if (cnr + 1.0 < cnr) {
        ii = 0;
        anew = cnr;
        apnd = cnr + 1.0;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(cnr) || muDoubleScalarIsInf(cnr + 1.0)) {
        ii = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
        n_too_large = !(cnr == cnr + 1.0);
      } else {
        anew = cnr;
        ndbl = muDoubleScalarFloor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
            muDoubleScalarMax(cnr, cnr + 1.0)) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n_too_large = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          ii = (int32_T)ndbl;
        } else {
          ii = 0;
        }
      }

      d_st.site = &ec_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &ad_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i28 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = ii;
      emxEnsureCapacity(&c_st, (emxArray__common *)cnrIdx, i28, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      if (ii > 0) {
        cnrIdx->data[0] = anew;
        if (ii > 1) {
          cnrIdx->data[ii - 1] = apnd;
          idx = (ii - 1) / 2;
          d_st.site = &fc_emlrtRSI;
          for (b_k = 1; b_k < idx; b_k++) {
            cnrIdx->data[b_k] = anew + (real_T)b_k;
            cnrIdx->data[(ii - b_k) - 1] = apnd - (real_T)b_k;
          }

          if (idx << 1 == ii - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (real_T)idx;
            cnrIdx->data[idx + 1] = apnd - (real_T)idx;
          }
        }
      }

      /*           keyboard  */
      idx = D->size[0];
      i28 = r14->size[0];
      r14->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r14, i28, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i28 = 0; i28 < b_loop_ub; i28++) {
        anew = cnrIdx->data[cnrIdx->size[0] * i28];
        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
        }

        i29 = (int32_T)anew;
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &qd_emlrtBCI, sp);
        }

        r14->data[i28] = i29 - 1;
      }

      iv51[0] = r14->size[0];
      if (!b4) {
        for (i28 = 0; i28 < 2; i28++) {
          iv52[i28] = 1 + i28;
        }

        b4 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv51, 1, iv52, 2, &k_emlrtECI, sp);
      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MGPm(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, dv5);
      idx = r14->size[0];
      for (i28 = 0; i28 < idx; i28++) {
        D->data[r14->data[i28]] = dv5[i28];
      }

      b_Dq = Dq->size[0];
      i28 = r14->size[0];
      r14->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r14, i28, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i28 = 0; i28 < b_loop_ub; i28++) {
        i29 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i28];
        if (!((i29 >= 1) && (i29 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, b_Dq, &he_emlrtBCI, sp);
        }

        r14->data[i28] = i29 - 1;
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      b_Dq = Dq->size[1];
      for (i28 = 0; i28 < 3; i28++) {
        i29 = (int32_T)(anew + (-2.0 + (real_T)i28));
        if (!((i29 >= 1) && (i29 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, b_Dq, &ie_emlrtBCI, sp);
        }

        iv53[i28] = i29 - 1;
      }

      iv54[0] = r14->size[0];
      iv54[1] = 3;
      if (!b5) {
        for (i28 = 0; i28 < 2; i28++) {
          iv55[i28] = 2 + i28;
        }

        b5 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv54, 2, iv55, 2, &l_emlrtECI, sp);
      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      MGPm_q(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      idx = r14->size[0];
      for (i28 = 0; i28 < 3; i28++) {
        for (i29 = 0; i29 < idx; i29++) {
          Dq->data[r14->data[i29] + Dq->size[0] * iv53[i28]] = b_X[i29 + idx *
            i28];
        }
      }

      idx = Dqq->size[0];
      i28 = r14->size[0];
      r14->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r14, i28, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i28 = 0; i28 < b_loop_ub; i28++) {
        i29 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i28];
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &qe_emlrtBCI, sp);
        }

        r14->data[i28] = i29 - 1;
      }

      iv56[0] = r14->size[0];
      if (!b6) {
        iv57[0] = 2;
        b6 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv56, 1, iv57, 1, &n_emlrtECI, sp);
      for (i28 = 0; i28 < 2; i28++) {
        b_comPoints[i28] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i28) - 1];
      }

      st.site = &sf_emlrtRSI;
      MGPm_qq(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
              DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, mxd,
              dv5);
      idx = r14->size[0];
      for (i28 = 0; i28 < idx; i28++) {
        Dqq->data[r14->data[i28]] = dv5[i28];
      }

      idx = Dt->size[0];
      i28 = r14->size[0];
      r14->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r14, i28, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i28 = 0; i28 < b_loop_ub; i28++) {
        i29 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i28];
        if (!((i29 >= 1) && (i29 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, idx, &re_emlrtBCI, sp);
        }

        r14->data[i28] = i29 - 1;
      }

      iv58[0] = r14->size[0];
      if (!b7) {
        iv59[0] = 2;
        b7 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv58, 1, iv59, 1, &m_emlrtECI, sp);

      /* MGPM_T */
      /*     C4_T = MGPM_T(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:22 */
      dv7[0] = 0.0;
      dv7[1] = -DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4
        + DNA_Pmpar->size[0] * k] * muDoubleScalarCos(t * DNA_Pmpar->data[4 +
        DNA_Pmpar->size[0] * k]);
      idx = r14->size[0];
      for (i28 = 0; i28 < idx; i28++) {
        Dt->data[r14->data[i28]] = dv7[i28];
      }

      /*  keyboard  */
      cnr += 2.0;
    } else {
      st.site = &pd_emlrtRSI;
      memcpy(&u[0], &varargin_1[0], 78U * sizeof(char_T));
      y = NULL;
      m7 = emlrtCreateCharArray(2, iv50);
      emlrtInitCharArrayR2013a(&st, 78, m7, &u[0]);
      emlrtAssign(&y, m7);
      b_st.site = &nh_emlrtRSI;
      g_error(&b_st, y, &emlrtMCI);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r14);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&Xd);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void d_getDk(const emlrtStack *sp, real_T t, const emxArray_real_T *state, const
             emxArray_real_T *DNA_incstr, const emxArray_real_T *DNA_edgelabel,
             const emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar,
             const emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
             const emxArray_real_T *DNA_Pmpar, emxArray_real_T *D,
             emxArray_real_T *Dq, emxArray_real_T *Dqq, emxArray_real_T *Dt,
             emxArray_real_T *Dqt, emxArray_real_T *Dtt)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  boolean_T b8;
  boolean_T b9;
  boolean_T b10;
  boolean_T b11;
  boolean_T b12;
  boolean_T b13;
  int32_T i34;
  int32_T loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  real_T nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  real_T nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  real_T nPm;
  real_T nC;
  int32_T i35;
  real_T anew;
  emxArray_real_T *X;
  int32_T iv61[2];
  emxArray_real_T *Xd;
  int32_T iv62[2];
  int32_T i36;
  int32_T b_loop_ub;
  real_T cnr;
  int32_T k;
  int32_T b_k;
  boolean_T x_data[100];
  int32_T idx;
  emxArray_real_T *cnrIdx;
  int32_T ii_data[100];
  emxArray_int32_T *r15;
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv63[2];
  int32_T massnr_data[100];
  boolean_T exitg1;
  boolean_T b_massnr_data[100];
  int32_T iv64[2];
  int32_T massnr_size[1];
  boolean_T guard1 = false;
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int32_T b_massnr_size[1];
  int32_T iv65[2];
  emxArray_boolean_T e_massnr_data;
  boolean_T f_massnr_data[100];
  int32_T i37;
  int32_T c_massnr_size[1];
  emxArray_boolean_T g_massnr_data;
  real_T mx[3];
  char_T u[78];
  static const char_T varargin_1[78] = { 'Y', 'o', 'u', ' ', 'c', 'a', 'n', ' ',
    'o', 'n', 'l', 'y', ' ', 'u', 's', 'e', ' ', 'e', 'd', 'g', 'e', ' ', '3',
    ',', ' ', 'i', '.', 'e', '.', ' ', 'p', 'e', 'n', 'd', 'u', 'l', 'u', 'm',
    ' ', 'o', 'n', ' ', 'c', 'a', 'r', 't', ',', ' ', 'i', 'f', ' ', 'i', 't',
    ' ', 'i', 's', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', 't',
    'o', ' ', 'a', ' ', 'g', 'r', 'o', 'u', 'n', 'd' };

  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv66[2] = { 1, 78 };

  real_T ndbl;
  real_T mxd[3];
  real_T b_X[6];
  real_T b_comPoints[2];
  real_T b_mx[6];
  real_T dv8[2];
  int32_T b_Dq;
  real_T b_mxd[6];
  real_T dv9[3];
  real_T c_comPoints[2];
  real_T apnd;
  boolean_T n_too_large;
  real_T cdiff;
  real_T MMHconstraintd[12];
  int32_T iv67[1];
  int32_T iv68[2];
  int32_T iv69[3];
  int32_T iv70[2];
  int32_T iv71[2];
  int32_T iv72[1];
  int32_T iv73[1];
  int32_T iv74[1];
  int32_T iv75[1];
  real_T dv10[2];
  int32_T iv76[1];
  int32_T iv77[1];
  int32_T iv78[1];
  int32_T iv79[1];
  real_T dv11[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &comPoints, 2, &cb_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  b8 = false;
  b9 = false;
  b10 = false;
  b11 = false;
  b12 = false;
  b13 = false;
  st.site = &xc_emlrtRSI;
  getCompoints(&st, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
               DNA_Ppar, DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i34 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i34, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i34 = 0; i34 < loop_ub; i34++) {
    b_DNA_edgelabel->data[i34] = (DNA_edgelabel->data[i34] == 1.0);
  }

  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &yc_emlrtRSI;
  nH = sum(&st, b_DNA_edgelabel);

  /* Number of hinges */
  i34 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i34, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i34 = 0; i34 < loop_ub; i34++) {
    c_DNA_edgelabel->data[i34] = (DNA_edgelabel->data[i34] == 3.0);
  }

  emxInit_boolean_T(sp, &d_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &ad_emlrtRSI;
  nP = sum(&st, c_DNA_edgelabel);
  i34 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_DNA_edgelabel, i34, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i34 = 0; i34 < loop_ub; i34++) {
    d_DNA_edgelabel->data[i34] = (DNA_edgelabel->data[i34] == 4.0);
  }

  emxInit_real_T(sp, &incH, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &incP, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &incPm, 2, &fb_emlrtRTEI, true);
  st.site = &bd_emlrtRSI;
  nPm = sum(&st, d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  st.site = &cd_emlrtRSI;
  b_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  st.site = &dd_emlrtRSI;
  c_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incP);
  st.site = &ed_emlrtRSI;
  d_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i34 = D->size[0];
  D->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)D, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i34 = 0; i34 < loop_ub; i34++) {
    D->data[i34] = 0.0;
  }

  /* For scleronomic constraints */
  i34 = DNA_Mpar->size[0];
  i35 = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int32_T)nC;
  anew = ((real_T)i34 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  Dq->size[1] = (int32_T)anew;
  emxEnsureCapacity(sp, (emxArray__common *)Dq, i35, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  anew = ((real_T)i34 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  loop_ub = (int32_T)nC * (int32_T)anew;
  for (i34 = 0; i34 < loop_ub; i34++) {
    Dq->data[i34] = 0.0;
  }

  i34 = Dqq->size[0];
  Dqq->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dqq, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i34 = 0; i34 < loop_ub; i34++) {
    Dqq->data[i34] = 0.0;
  }

  i34 = Dt->size[0];
  Dt->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dt, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i34 = 0; i34 < loop_ub; i34++) {
    Dt->data[i34] = 0.0;
  }

  /* Extra for rheonomic constraints */
  i34 = Dqt->size[0];
  Dqt->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dqt, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i34 = 0; i34 < loop_ub; i34++) {
    Dqt->data[i34] = 0.0;
  }

  i34 = Dtt->size[0];
  Dtt->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)Dtt, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  for (i34 = 0; i34 < loop_ub; i34++) {
    Dtt->data[i34] = 0.0;
  }

  anew = (real_T)state->size[0] / 2.0;
  if (1.0 > anew) {
    loop_ub = 0;
  } else {
    i34 = state->size[0];
    if (!(1 <= i34)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i34, &qc_emlrtBCI, sp);
    }

    if (anew != muDoubleScalarFloor(anew)) {
      emlrtIntegerCheckR2012b(anew, &g_emlrtDCI, sp);
    }

    i34 = state->size[0];
    loop_ub = (int32_T)anew;
    if (!(loop_ub <= i34)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i34, &qc_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &X, 2, &gb_emlrtRTEI, true);
  iv61[0] = 1;
  iv61[1] = loop_ub;
  st.site = &fd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv61);
  i34 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)X, i34, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (i34 = 0; i34 < loop_ub; i34++) {
    X->data[X->size[0] * i34] = state->data[i34];
  }

  anew = (real_T)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i35 = 1;
    i34 = 1;
  } else {
    if (anew + 1.0 != muDoubleScalarFloor(anew + 1.0)) {
      emlrtIntegerCheckR2012b(anew + 1.0, &h_emlrtDCI, sp);
    }

    i34 = state->size[0];
    i35 = (int32_T)(anew + 1.0);
    if (!((i35 >= 1) && (i35 <= i34))) {
      emlrtDynamicBoundsCheckR2012b(i35, 1, i34, &rc_emlrtBCI, sp);
    }

    i34 = state->size[0];
    i36 = state->size[0];
    if (!((i36 >= 1) && (i36 <= i34))) {
      emlrtDynamicBoundsCheckR2012b(i36, 1, i34, &rc_emlrtBCI, sp);
    }

    i34 = i36 + 1;
  }

  emxInit_real_T(sp, &Xd, 2, &pb_emlrtRTEI, true);
  iv62[0] = 1;
  iv62[1] = i34 - i35;
  st.site = &gd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv62);
  i36 = Xd->size[0] * Xd->size[1];
  Xd->size[0] = 1;
  Xd->size[1] = i34 - i35;
  emxEnsureCapacity(sp, (emxArray__common *)Xd, i36, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  b_loop_ub = i34 - i35;
  for (i36 = 0; i36 < b_loop_ub; i36++) {
    Xd->data[Xd->size[0] * i36] = state->data[(i35 + i36) - 1];
  }

  /* For rotational joint */
  cnr = 1.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nH, mxDOUBLE_CLASS, (int32_T)nH,
    &bd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nH - 1) {
    st.site = &hd_emlrtRSI;
    b_loop_ub = incH->size[0];
    i36 = incH->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i36))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i36, &sc_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      x_data[i36] = (incH->data[i36 + incH->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= b_loop_ub)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i36 = 0;
      } else {
        i36 = idx;
      }

      iv63[0] = 1;
      iv63[1] = i36;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv63);
      b_loop_ub = i36;
    }

    for (i36 = 0; i36 < b_loop_ub; i36++) {
      massnr_data[i36] = ii_data[i36];
    }

    /* Find entries in column */
    massnr_size[0] = b_loop_ub;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      b_massnr_data[i36] = (massnr_data[i36] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int32_T *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    st.site = &id_emlrtRSI;
    if (any(&st, &c_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &tc_emlrtBCI, sp);
      }

      i36 = DNA_Hpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &uc_emlrtBCI, sp);
      }

      i36 = comPoints->size[0];
      i37 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &vc_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, loop_ub, &ae_emlrtBCI, sp);
        }

        mx[i36] = X->data[i37 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i34 - i35;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &be_emlrtBCI, sp);
        }

        mxd[i36] = Xd->data[i37 - 1];
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MGH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, dv8);
      idx = D->size[0];
      for (i36 = 0; i36 < 2; i36++) {
        i37 = (int32_T)(cnr + (real_T)i36);
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &ce_emlrtBCI, sp);
        }

        D->data[i37 - 1] = dv8[i36];
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MGH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i36 = 0; i36 < 3; i36++) {
        for (i37 = 0; i37 < 2; i37++) {
          ii = (int32_T)(cnr + (real_T)i37);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &oe_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i36));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &pe_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = b_X[i37 + (i36 << 1)];
        }
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      st.site = &pf_emlrtRSI;
      MGH_qq(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             mx, mxd, dv8);
      idx = Dqq->size[0];
      for (i36 = 0; i36 < 2; i36++) {
        i37 = (int32_T)(cnr + (real_T)i36);
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &ue_emlrtBCI, sp);
        }

        Dqq->data[i37 - 1] = dv8[i36];
      }

      cnr += 2.0;
    } else {
      if (!(1 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_loop_ub, &wc_emlrtBCI, sp);
      }

      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &xc_emlrtBCI, sp);
      }

      i36 = DNA_Hpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &yc_emlrtBCI, sp);
      }

      i36 = comPoints->size[0];
      i37 = (int32_T)((real_T)massnr_data[0] - 1.0);
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &ad_emlrtBCI, sp);
      }

      i36 = comPoints->size[0];
      i37 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &bd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, loop_ub, &ud_emlrtBCI, sp);
        }

        b_X[i36] = X->data[i37 - 1];
      }

      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(ndbl + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, loop_ub, &vd_emlrtBCI, sp);
        }

        b_X[i36 + 3] = X->data[i37 - 1];
      }

      for (i36 = 0; i36 < 6; i36++) {
        b_mx[i36] = b_X[i36];
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = i34 - i35;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = i34 - i35;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &wd_emlrtBCI, sp);
        }

        b_X[i36] = Xd->data[i37 - 1];
      }

      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(ndbl + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, ii, &xd_emlrtBCI, sp);
        }

        b_X[i36 + 3] = Xd->data[i37 - 1];
      }

      for (i36 = 0; i36 < 6; i36++) {
        b_mxd[i36] = b_X[i36];
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      for (i36 = 0; i36 < 2; i36++) {
        c_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MMH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, dv8);
      idx = D->size[0];
      for (i36 = 0; i36 < 2; i36++) {
        i37 = (int32_T)(cnr + (real_T)i36);
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &yd_emlrtBCI, sp);
        }

        D->data[i37 - 1] = dv8[i36];
      }

      /* Constraints */
      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      for (i36 = 0; i36 < 2; i36++) {
        c_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MMH_q(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i36 = 0; i36 < 3; i36++) {
        for (i37 = 0; i37 < 2; i37++) {
          ii = (int32_T)(cnr + (real_T)i37);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &ke_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i36));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &le_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i37 +
            (i36 << 1)];
        }
      }

      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      for (i36 = 0; i36 < 3; i36++) {
        for (i37 = 0; i37 < 2; i37++) {
          ii = (int32_T)(cnr + (real_T)i37);
          if (!((ii >= 1) && (ii <= b_Dq))) {
            emlrtDynamicBoundsCheckR2012b(ii, 1, b_Dq, &me_emlrtBCI, sp);
          }

          b_k = (int32_T)(anew + (-2.0 + (real_T)i36));
          if (!((b_k >= 1) && (b_k <= idx))) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, idx, &ne_emlrtBCI, sp);
          }

          Dq->data[(ii + Dq->size[0] * (b_k - 1)) - 1] = MMHconstraintd[i37 +
            ((3 + i36) << 1)];
        }
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      for (i36 = 0; i36 < 2; i36++) {
        c_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      st.site = &qf_emlrtRSI;
      MMH_qq(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             c_comPoints, b_mx, b_mxd, dv8);
      idx = Dqq->size[0];
      for (i36 = 0; i36 < 2; i36++) {
        i37 = (int32_T)(cnr + (real_T)i36);
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &te_emlrtBCI, sp);
        }

        Dqq->data[i37 - 1] = dv8[i36];
      }

      /* Double derivative of constraints */
      cnr += 2.0;
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nP, mxDOUBLE_CLASS, (int32_T)nP,
    &cd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nP - 1) {
    st.site = &jd_emlrtRSI;
    b_loop_ub = incP->size[0];
    i36 = incP->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i36))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i36, &cd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      x_data[i36] = (incP->data[i36 + incP->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= b_loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i36 = 0;
      } else {
        i36 = idx;
      }

      iv64[0] = 1;
      iv64[1] = i36;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv64);
      b_loop_ub = i36;
    }

    for (i36 = 0; i36 < b_loop_ub; i36++) {
      massnr_data[i36] = ii_data[i36];
    }

    /* Find entries in column */
    b_massnr_size[0] = b_loop_ub;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      d_massnr_data[i36] = (massnr_data[i36] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int32_T *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    st.site = &kd_emlrtRSI;
    if (any(&st, &e_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &dd_emlrtBCI, sp);
      }

      i36 = DNA_Ppar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &ed_emlrtBCI, sp);
      }

      i36 = DNA_Ppar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &fd_emlrtBCI, sp);
      }

      i36 = comPoints->size[0];
      i37 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &gd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, loop_ub, &rd_emlrtBCI, sp);
        }

        mx[i36] = X->data[i37 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i34 - i35;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &sd_emlrtBCI, sp);
        }

        mxd[i36] = Xd->data[i37 - 1];
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      i36 = D->size[0];
      i37 = (int32_T)cnr;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &td_emlrtBCI, sp);
      }

      D->data[i37 - 1] = MGP(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] *
        k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MGP_q(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv9);
      b_Dq = Dq->size[0];
      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Dq->size[1];
      i36 = (int32_T)cnr;
      if (!((i36 >= 1) && (i36 <= b_Dq))) {
        emlrtDynamicBoundsCheckR2012b(i36, 1, b_Dq, &ge_emlrtBCI, sp);
      }

      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &je_emlrtBCI, sp);
        }

        Dq->data[((int32_T)cnr + Dq->size[0] * (i37 - 1)) - 1] = dv9[i36];
      }

      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      i36 = Dqq->size[0];
      i37 = (int32_T)cnr;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &se_emlrtBCI, sp);
      }

      st.site = &rf_emlrtRSI;
      Dqq->data[i37 - 1] = MGP_qq(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx,
        mxd);
      cnr++;
    } else {
      st.site = &ld_emlrtRSI;
      error(&st);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nPm, mxDOUBLE_CLASS, (int32_T)nPm,
    &dd_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T(sp, &cnrIdx, 2, &hb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r15, 1, &bb_emlrtRTEI, true);
  while (k <= (int32_T)nPm - 1) {
    st.site = &md_emlrtRSI;
    b_loop_ub = incPm->size[0];
    i36 = incPm->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i36))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i36, &hd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      x_data[i36] = (incPm->data[i36 + incPm->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= b_loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i36 = 0;
      } else {
        i36 = idx;
      }

      iv65[0] = 1;
      iv65[1] = i36;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv65);
      b_loop_ub = i36;
    }

    for (i36 = 0; i36 < b_loop_ub; i36++) {
      massnr_data[i36] = ii_data[i36];
    }

    /* Find entries in column */
    c_massnr_size[0] = b_loop_ub;
    for (i36 = 0; i36 < b_loop_ub; i36++) {
      f_massnr_data[i36] = (massnr_data[i36] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int32_T *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    st.site = &nd_emlrtRSI;
    if (any(&st, &g_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &id_emlrtBCI, sp);
      }

      i36 = DNA_Pmpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &jd_emlrtBCI, sp);
      }

      i36 = DNA_Pmpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &kd_emlrtBCI, sp);
      }

      i36 = DNA_Pmpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &ld_emlrtBCI, sp);
      }

      i36 = DNA_Pmpar->size[1];
      i37 = k + 1;
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &md_emlrtBCI, sp);
      }

      /*          keyboard  */
      i36 = comPoints->size[0];
      i37 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i37 >= 1) && (i37 <= i36))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, i36, &nd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, loop_ub, &od_emlrtBCI, sp);
        }

        mx[i36] = X->data[i37 - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i34 - i35;
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &pd_emlrtBCI, sp);
        }

        mxd[i36] = Xd->data[i37 - 1];
      }

      st.site = &od_emlrtRSI;
      b_st.site = &wd_emlrtRSI;
      c_st.site = &dc_emlrtRSI;
      if (cnr + 1.0 < cnr) {
        ii = 0;
        anew = cnr;
        apnd = cnr + 1.0;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(cnr) || muDoubleScalarIsInf(cnr + 1.0)) {
        ii = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
        n_too_large = !(cnr == cnr + 1.0);
      } else {
        anew = cnr;
        ndbl = muDoubleScalarFloor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
            muDoubleScalarMax(cnr, cnr + 1.0)) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n_too_large = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          ii = (int32_T)ndbl;
        } else {
          ii = 0;
        }
      }

      d_st.site = &ec_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &ad_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i36 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = ii;
      emxEnsureCapacity(&c_st, (emxArray__common *)cnrIdx, i36, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      if (ii > 0) {
        cnrIdx->data[0] = anew;
        if (ii > 1) {
          cnrIdx->data[ii - 1] = apnd;
          idx = (ii - 1) / 2;
          d_st.site = &fc_emlrtRSI;
          for (b_k = 1; b_k < idx; b_k++) {
            cnrIdx->data[b_k] = anew + (real_T)b_k;
            cnrIdx->data[(ii - b_k) - 1] = apnd - (real_T)b_k;
          }

          if (idx << 1 == ii - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (real_T)idx;
            cnrIdx->data[idx + 1] = apnd - (real_T)idx;
          }
        }
      }

      /*           keyboard  */
      idx = D->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        anew = cnrIdx->data[cnrIdx->size[0] * i36];
        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
        }

        i37 = (int32_T)anew;
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &qd_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      iv67[0] = r15->size[0];
      if (!b8) {
        for (i36 = 0; i36 < 2; i36++) {
          iv68[i36] = 1 + i36;
        }

        b8 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv67, 1, iv68, 2, &k_emlrtECI, sp);
      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MGPm(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, dv8);
      idx = r15->size[0];
      for (i36 = 0; i36 < idx; i36++) {
        D->data[r15->data[i36]] = dv8[i36];
      }

      b_Dq = Dq->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        i37 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i36];
        if (!((i37 >= 1) && (i37 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, b_Dq, &he_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      b_Dq = Dq->size[1];
      for (i36 = 0; i36 < 3; i36++) {
        i37 = (int32_T)(anew + (-2.0 + (real_T)i36));
        if (!((i37 >= 1) && (i37 <= b_Dq))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, b_Dq, &ie_emlrtBCI, sp);
        }

        iv69[i36] = i37 - 1;
      }

      iv70[0] = r15->size[0];
      iv70[1] = 3;
      if (!b9) {
        for (i36 = 0; i36 < 2; i36++) {
          iv71[i36] = 2 + i36;
        }

        b9 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv70, 2, iv71, 2, &l_emlrtECI, sp);
      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      MGPm_q(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      idx = r15->size[0];
      for (i36 = 0; i36 < 3; i36++) {
        for (i37 = 0; i37 < idx; i37++) {
          Dq->data[r15->data[i37] + Dq->size[0] * iv69[i36]] = b_X[i37 + idx *
            i36];
        }
      }

      idx = Dqq->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        i37 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i36];
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &qe_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      iv72[0] = r15->size[0];
      if (!b10) {
        iv73[0] = 2;
        b10 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv72, 1, iv73, 1, &n_emlrtECI, sp);
      for (i36 = 0; i36 < 2; i36++) {
        b_comPoints[i36] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i36) - 1];
      }

      st.site = &sf_emlrtRSI;
      MGPm_qq(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
              DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, mxd,
              dv8);
      idx = r15->size[0];
      for (i36 = 0; i36 < idx; i36++) {
        Dqq->data[r15->data[i36]] = dv8[i36];
      }

      idx = Dt->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        i37 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i36];
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &re_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      iv74[0] = r15->size[0];
      if (!b11) {
        iv75[0] = 2;
        b11 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv74, 1, iv75, 1, &m_emlrtECI, sp);

      /* MGPM_T */
      /*     C4_T = MGPM_T(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:22 */
      dv10[0] = 0.0;
      dv10[1] = -DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4
        + DNA_Pmpar->size[0] * k] * muDoubleScalarCos(t * DNA_Pmpar->data[4 +
        DNA_Pmpar->size[0] * k]);
      idx = r15->size[0];
      for (i36 = 0; i36 < idx; i36++) {
        Dt->data[r15->data[i36]] = dv10[i36];
      }

      idx = Dqt->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        i37 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i36];
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &hf_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      iv76[0] = r15->size[0];
      if (!b12) {
        iv77[0] = 2;
        b12 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv76, 1, iv77, 1, &p_emlrtECI, sp);
      idx = r15->size[0];
      for (i36 = 0; i36 < idx; i36++) {
        Dqt->data[r15->data[i36]] = 0.0;
      }

      idx = Dtt->size[0];
      i36 = r15->size[0];
      r15->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r15, i36, (int32_T)sizeof
                        (int32_T), &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        i37 = (int32_T)cnrIdx->data[cnrIdx->size[0] * i36];
        if (!((i37 >= 1) && (i37 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i37, 1, idx, &if_emlrtBCI, sp);
        }

        r15->data[i36] = i37 - 1;
      }

      iv78[0] = r15->size[0];
      if (!b13) {
        iv79[0] = 2;
        b13 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv78, 1, iv79, 1, &q_emlrtECI, sp);
      st.site = &ig_emlrtRSI;

      /* MGPM_TT */
      /*     C4_TT = MGPM_TT(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:23 */
      b_st.site = &jg_emlrtRSI;
      c_st.site = &uf_emlrtRSI;
      dv11[0] = 0.0;
      dv11[1] = DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * (DNA_Pmpar->data[4
        + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k])
        * muDoubleScalarSin(t * DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k]);
      idx = r15->size[0];
      for (i36 = 0; i36 < idx; i36++) {
        Dtt->data[r15->data[i36]] = dv11[i36];
      }

      /*  keyboard  */
      cnr += 2.0;
    } else {
      st.site = &pd_emlrtRSI;
      memcpy(&u[0], &varargin_1[0], 78U * sizeof(char_T));
      y = NULL;
      m8 = emlrtCreateCharArray(2, iv66);
      emlrtInitCharArrayR2013a(&st, 78, m8, &u[0]);
      emlrtAssign(&y, m8);
      b_st.site = &nh_emlrtRSI;
      g_error(&b_st, y, &emlrtMCI);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r15);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&Xd);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void getDk(const emlrtStack *sp, real_T t, const emxArray_real_T *state, const
           emxArray_real_T *DNA_incstr, const emxArray_real_T *DNA_edgelabel,
           const emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar,
           const emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
           const emxArray_real_T *DNA_Pmpar, emxArray_real_T *D)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  boolean_T b1;
  int32_T i11;
  int32_T loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  real_T nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  real_T nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  real_T nPm;
  real_T nC;
  real_T anew;
  emxArray_real_T *X;
  int32_T iv10[2];
  int32_T i12;
  int32_T iv11[2];
  int32_T i13;
  real_T cnr;
  int32_T k;
  int32_T b_loop_ub;
  int32_T b_k;
  boolean_T x_data[100];
  int32_T idx;
  emxArray_real_T *cnrIdx;
  int32_T ii_data[100];
  emxArray_int32_T *r6;
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv12[2];
  int32_T massnr_data[100];
  boolean_T exitg1;
  boolean_T b_massnr_data[100];
  int32_T iv13[2];
  int32_T massnr_size[1];
  boolean_T guard1 = false;
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int32_T b_massnr_size[1];
  int32_T iv14[2];
  emxArray_boolean_T e_massnr_data;
  boolean_T f_massnr_data[100];
  int32_T c_massnr_size[1];
  char_T u[78];
  static const char_T varargin_1[78] = { 'Y', 'o', 'u', ' ', 'c', 'a', 'n', ' ',
    'o', 'n', 'l', 'y', ' ', 'u', 's', 'e', ' ', 'e', 'd', 'g', 'e', ' ', '3',
    ',', ' ', 'i', '.', 'e', '.', ' ', 'p', 'e', 'n', 'd', 'u', 'l', 'u', 'm',
    ' ', 'o', 'n', ' ', 'c', 'a', 'r', 't', ',', ' ', 'i', 'f', ' ', 'i', 't',
    ' ', 'i', 's', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', 't',
    'o', ' ', 'a', ' ', 'g', 'r', 'o', 'u', 'n', 'd' };

  emxArray_boolean_T g_massnr_data;
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv15[2] = { 1, 78 };

  real_T mx[3];
  char_T b_u[78];
  const mxArray *b_y;
  static const int32_T iv16[2] = { 1, 78 };

  real_T ndbl;
  real_T b_X[6];
  real_T b_comPoints[2];
  real_T dv2[2];
  real_T b_mx[6];
  real_T c_comPoints[2];
  real_T apnd;
  boolean_T n_too_large;
  real_T cdiff;
  int32_T iv17[1];
  int32_T iv18[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &comPoints, 2, &cb_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  b1 = false;
  st.site = &xc_emlrtRSI;
  getCompoints(&st, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
               DNA_Ppar, DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i11 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i11, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    b_DNA_edgelabel->data[i11] = (DNA_edgelabel->data[i11] == 1.0);
  }

  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &yc_emlrtRSI;
  nH = sum(&st, b_DNA_edgelabel);

  /* Number of hinges */
  i11 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i11, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i11 = 0; i11 < loop_ub; i11++) {
    c_DNA_edgelabel->data[i11] = (DNA_edgelabel->data[i11] == 3.0);
  }

  emxInit_boolean_T(sp, &d_DNA_edgelabel, 2, &bb_emlrtRTEI, true);
  st.site = &ad_emlrtRSI;
  nP = sum(&st, c_DNA_edgelabel);
  i11 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_DNA_edgelabel, i11, (int32_T)
                    sizeof(boolean_T), &bb_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i11 = 0; i11 < loop_ub; i11++) {
    d_DNA_edgelabel->data[i11] = (DNA_edgelabel->data[i11] == 4.0);
  }

  emxInit_real_T(sp, &incH, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &incP, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &incPm, 2, &fb_emlrtRTEI, true);
  st.site = &bd_emlrtRSI;
  nPm = sum(&st, d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  st.site = &cd_emlrtRSI;
  b_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  st.site = &dd_emlrtRSI;
  c_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incP);
  st.site = &ed_emlrtRSI;
  d_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i11 = D->size[0];
  D->size[0] = (int32_T)nC;
  emxEnsureCapacity(sp, (emxArray__common *)D, i11, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i11 = 0; i11 < loop_ub; i11++) {
    D->data[i11] = 0.0;
  }

  /* For scleronomic constraints */
  i11 = DNA_Mpar->size[0];
  anew = ((real_T)i11 - 1.0) * 3.0;
  if (!(anew >= 0.0)) {
    emlrtNonNegativeCheckR2012b(anew, &f_emlrtDCI, sp);
  }

  /* Extra for rheonomic constraints */
  anew = (real_T)state->size[0] / 2.0;
  if (1.0 > anew) {
    loop_ub = 0;
  } else {
    i11 = state->size[0];
    if (!(1 <= i11)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i11, &qc_emlrtBCI, sp);
    }

    if (anew != muDoubleScalarFloor(anew)) {
      emlrtIntegerCheckR2012b(anew, &g_emlrtDCI, sp);
    }

    i11 = state->size[0];
    loop_ub = (int32_T)anew;
    if (!(loop_ub <= i11)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i11, &qc_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &X, 2, &gb_emlrtRTEI, true);
  iv10[0] = 1;
  iv10[1] = loop_ub;
  st.site = &fd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv10);
  i11 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)X, i11, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (i11 = 0; i11 < loop_ub; i11++) {
    X->data[X->size[0] * i11] = state->data[i11];
  }

  anew = (real_T)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i12 = 1;
    i11 = 1;
  } else {
    if (anew + 1.0 != muDoubleScalarFloor(anew + 1.0)) {
      emlrtIntegerCheckR2012b(anew + 1.0, &h_emlrtDCI, sp);
    }

    i11 = state->size[0];
    i12 = (int32_T)(anew + 1.0);
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, &rc_emlrtBCI, sp);
    }

    i11 = state->size[0];
    i13 = state->size[0];
    if (!((i13 >= 1) && (i13 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i13, 1, i11, &rc_emlrtBCI, sp);
    }

    i11 = i13 + 1;
  }

  iv11[0] = 1;
  iv11[1] = i11 - i12;
  st.site = &gd_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv11);

  /* For rotational joint */
  cnr = 1.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nH, mxDOUBLE_CLASS, (int32_T)nH,
    &bd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nH - 1) {
    st.site = &hd_emlrtRSI;
    b_loop_ub = incH->size[0];
    i13 = incH->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i13, &sc_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      x_data[i13] = (incH->data[i13 + incH->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= b_loop_ub)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i13 = 0;
      } else {
        i13 = idx;
      }

      iv12[0] = 1;
      iv12[1] = i13;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv12);
      b_loop_ub = i13;
    }

    for (i13 = 0; i13 < b_loop_ub; i13++) {
      massnr_data[i13] = ii_data[i13];
    }

    /* Find entries in column */
    massnr_size[0] = b_loop_ub;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      b_massnr_data[i13] = (massnr_data[i13] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int32_T *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    st.site = &id_emlrtRSI;
    if (any(&st, &c_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &tc_emlrtBCI, sp);
      }

      i13 = DNA_Hpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &uc_emlrtBCI, sp);
      }

      i13 = comPoints->size[0];
      ii = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &vc_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &ae_emlrtBCI, sp);
        }

        mx[i13] = X->data[ii - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i11 - i12;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &be_emlrtBCI, sp);
        }
      }

      for (i13 = 0; i13 < 2; i13++) {
        b_comPoints[i13] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i13) - 1];
      }

      MGH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, dv2);
      idx = D->size[0];
      for (i13 = 0; i13 < 2; i13++) {
        ii = (int32_T)(cnr + (real_T)i13);
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &ce_emlrtBCI, sp);
        }

        D->data[ii - 1] = dv2[i13];
      }

      cnr += 2.0;
    } else {
      if (!(1 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_loop_ub, &wc_emlrtBCI, sp);
      }

      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &xc_emlrtBCI, sp);
      }

      i13 = DNA_Hpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &yc_emlrtBCI, sp);
      }

      i13 = comPoints->size[0];
      ii = (int32_T)((real_T)massnr_data[0] - 1.0);
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &ad_emlrtBCI, sp);
      }

      i13 = comPoints->size[0];
      ii = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &bd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &ud_emlrtBCI, sp);
        }

        b_X[i13] = X->data[ii - 1];
      }

      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(ndbl + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &vd_emlrtBCI, sp);
        }

        b_X[i13 + 3] = X->data[ii - 1];
      }

      for (i13 = 0; i13 < 6; i13++) {
        b_mx[i13] = b_X[i13];
      }

      anew = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = i11 - i12;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &wd_emlrtBCI, sp);
        }
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i11 - i12;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &xd_emlrtBCI, sp);
        }
      }

      for (i13 = 0; i13 < 2; i13++) {
        b_comPoints[i13] = comPoints->data[((int32_T)((real_T)massnr_data[0] -
          1.0) + comPoints->size[0] * i13) - 1];
      }

      for (i13 = 0; i13 < 2; i13++) {
        c_comPoints[i13] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i13) - 1];
      }

      MMH(*(real_T (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, dv2);
      idx = D->size[0];
      for (i13 = 0; i13 < 2; i13++) {
        ii = (int32_T)(cnr + (real_T)i13);
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &yd_emlrtBCI, sp);
        }

        D->data[ii - 1] = dv2[i13];
      }

      /* Constraints */
      cnr += 2.0;
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nP, mxDOUBLE_CLASS, (int32_T)nP,
    &cd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nP - 1) {
    st.site = &jd_emlrtRSI;
    b_loop_ub = incP->size[0];
    i13 = incP->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i13, &cd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      x_data[i13] = (incP->data[i13 + incP->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= b_loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i13 = 0;
      } else {
        i13 = idx;
      }

      iv13[0] = 1;
      iv13[1] = i13;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv13);
      b_loop_ub = i13;
    }

    for (i13 = 0; i13 < b_loop_ub; i13++) {
      massnr_data[i13] = ii_data[i13];
    }

    /* Find entries in column */
    b_massnr_size[0] = b_loop_ub;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      d_massnr_data[i13] = (massnr_data[i13] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int32_T *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    st.site = &kd_emlrtRSI;
    if (any(&st, &e_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &dd_emlrtBCI, sp);
      }

      i13 = DNA_Ppar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &ed_emlrtBCI, sp);
      }

      i13 = DNA_Ppar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &fd_emlrtBCI, sp);
      }

      i13 = comPoints->size[0];
      ii = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &gd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &rd_emlrtBCI, sp);
        }

        mx[i13] = X->data[ii - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i11 - i12;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &sd_emlrtBCI, sp);
        }
      }

      for (i13 = 0; i13 < 2; i13++) {
        b_comPoints[i13] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i13) - 1];
      }

      i13 = D->size[0];
      ii = (int32_T)cnr;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &td_emlrtBCI, sp);
      }

      D->data[ii - 1] = MGP(*(real_T (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] *
                            k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k],
                            b_comPoints, mx);
      cnr++;
    } else {
      st.site = &ld_emlrtRSI;
      memcpy(&u[0], &varargin_1[0], 78U * sizeof(char_T));
      y = NULL;
      m1 = emlrtCreateCharArray(2, iv15);
      emlrtInitCharArrayR2013a(&st, 78, m1, &u[0]);
      emlrtAssign(&y, m1);
      b_st.site = &nh_emlrtRSI;
      g_error(&b_st, y, &emlrtMCI);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nPm, mxDOUBLE_CLASS, (int32_T)nPm,
    &dd_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T(sp, &cnrIdx, 2, &hb_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r6, 1, &bb_emlrtRTEI, true);
  while (k <= (int32_T)nPm - 1) {
    st.site = &md_emlrtRSI;
    b_loop_ub = incPm->size[0];
    i13 = incPm->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i13, &hd_emlrtBCI, &st);
    }

    b_k = k + 1;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      x_data[i13] = (incPm->data[i13 + incPm->size[0] * (b_k - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    c_st.site = &mb_emlrtRSI;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= b_loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= b_loop_ub) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (idx <= b_loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (b_loop_ub == 1) {
      if (idx == 0) {
        b_loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i13 = 0;
      } else {
        i13 = idx;
      }

      iv14[0] = 1;
      iv14[1] = i13;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, b_loop_ub, iv14);
      b_loop_ub = i13;
    }

    for (i13 = 0; i13 < b_loop_ub; i13++) {
      massnr_data[i13] = ii_data[i13];
    }

    /* Find entries in column */
    c_massnr_size[0] = b_loop_ub;
    for (i13 = 0; i13 < b_loop_ub; i13++) {
      f_massnr_data[i13] = (massnr_data[i13] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int32_T *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    st.site = &nd_emlrtRSI;
    if (any(&st, &g_massnr_data)) {
      /* If this column contains ground */
      if (!(2 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_loop_ub, &id_emlrtBCI, sp);
      }

      i13 = DNA_Pmpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &jd_emlrtBCI, sp);
      }

      i13 = DNA_Pmpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &kd_emlrtBCI, sp);
      }

      i13 = DNA_Pmpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &ld_emlrtBCI, sp);
      }

      i13 = DNA_Pmpar->size[1];
      ii = k + 1;
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &md_emlrtBCI, sp);
      }

      /*          keyboard  */
      i13 = comPoints->size[0];
      ii = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((ii >= 1) && (ii <= i13))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &nd_emlrtBCI, sp);
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &od_emlrtBCI, sp);
        }

        mx[i13] = X->data[ii - 1];
      }

      anew = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = i11 - i12;
      for (i13 = 0; i13 < 3; i13++) {
        ii = (int32_T)(anew + (-2.0 + (real_T)i13));
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &pd_emlrtBCI, sp);
        }
      }

      st.site = &od_emlrtRSI;
      b_st.site = &wd_emlrtRSI;
      c_st.site = &dc_emlrtRSI;
      if (cnr + 1.0 < cnr) {
        ii = 0;
        anew = cnr;
        apnd = cnr + 1.0;
        n_too_large = false;
      } else if (muDoubleScalarIsInf(cnr) || muDoubleScalarIsInf(cnr + 1.0)) {
        ii = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
        n_too_large = !(cnr == cnr + 1.0);
      } else {
        anew = cnr;
        ndbl = muDoubleScalarFloor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
            muDoubleScalarMax(cnr, cnr + 1.0)) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n_too_large = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          ii = (int32_T)ndbl;
        } else {
          ii = 0;
        }
      }

      d_st.site = &ec_emlrtRSI;
      if (!n_too_large) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &ad_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i13 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = ii;
      emxEnsureCapacity(&c_st, (emxArray__common *)cnrIdx, i13, (int32_T)sizeof
                        (real_T), &bb_emlrtRTEI);
      if (ii > 0) {
        cnrIdx->data[0] = anew;
        if (ii > 1) {
          cnrIdx->data[ii - 1] = apnd;
          idx = (ii - 1) / 2;
          d_st.site = &fc_emlrtRSI;
          for (b_k = 1; b_k < idx; b_k++) {
            cnrIdx->data[b_k] = anew + (real_T)b_k;
            cnrIdx->data[(ii - b_k) - 1] = apnd - (real_T)b_k;
          }

          if (idx << 1 == ii - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (real_T)idx;
            cnrIdx->data[idx + 1] = apnd - (real_T)idx;
          }
        }
      }

      /*           keyboard  */
      idx = D->size[0];
      i13 = r6->size[0];
      r6->size[0] = cnrIdx->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r6, i13, (int32_T)sizeof(int32_T),
                        &bb_emlrtRTEI);
      b_loop_ub = cnrIdx->size[1];
      for (i13 = 0; i13 < b_loop_ub; i13++) {
        anew = cnrIdx->data[cnrIdx->size[0] * i13];
        if (anew != (int32_T)muDoubleScalarFloor(anew)) {
          emlrtIntegerCheckR2012b(anew, &i_emlrtDCI, sp);
        }

        ii = (int32_T)anew;
        if (!((ii >= 1) && (ii <= idx))) {
          emlrtDynamicBoundsCheckR2012b(ii, 1, idx, &qd_emlrtBCI, sp);
        }

        r6->data[i13] = ii - 1;
      }

      iv17[0] = r6->size[0];
      if (!b1) {
        for (i13 = 0; i13 < 2; i13++) {
          iv18[i13] = 1 + i13;
        }

        b1 = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv17, 1, iv18, 2, &k_emlrtECI, sp);
      for (i13 = 0; i13 < 2; i13++) {
        b_comPoints[i13] = comPoints->data[((int32_T)((real_T)massnr_data[1] -
          1.0) + comPoints->size[0] * i13) - 1];
      }

      MGPm(*(real_T (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, dv2);
      idx = r6->size[0];
      for (i13 = 0; i13 < idx; i13++) {
        D->data[r6->data[i13]] = dv2[i13];
      }

      /*  keyboard  */
      cnr += 2.0;
    } else {
      st.site = &pd_emlrtRSI;
      memcpy(&b_u[0], &varargin_1[0], 78U * sizeof(char_T));
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv16);
      emlrtInitCharArrayR2013a(&st, 78, m1, &b_u[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &nh_emlrtRSI;
      g_error(&b_st, b_y, &emlrtMCI);
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r6);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (getDk.c) */
