/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getForces.c
 *
 * Code generation for function 'getForces'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getForces.h"
#include "simulateDNA_emxutil.h"
#include "error1.h"
#include "MMtorsion.h"
#include "any.h"
#include "indexShapeCheck.h"
#include "MGspringforce.h"
#include "DNA2inc.h"
#include "sum.h"
#include "getCompoints.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kg_emlrtRSI = { 9, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo lg_emlrtRSI = { 10, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo mg_emlrtRSI = { 12, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo ng_emlrtRSI = { 19, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo og_emlrtRSI = { 20, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo pg_emlrtRSI = { 23, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo qg_emlrtRSI = { 24, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo rg_emlrtRSI = { 33, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo sg_emlrtRSI = { 38, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo tg_emlrtRSI = { 69, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo ug_emlrtRSI = { 76, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo vg_emlrtRSI = { 81, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo wg_emlrtRSI = { 92, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRSInfo dh_emlrtRSI = { 40, "MMspringforce",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMspringforce.m"
};

static emlrtRSInfo eh_emlrtRSI = { 41, "MMspringforce",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMspringforce.m"
};

static emlrtRSInfo fh_emlrtRSI = { 43, "MMspringforce",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMspringforce.m"
};

static emlrtRSInfo gh_emlrtRSI = { 44, "MMspringforce",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\deriveTerms\\MMspringforce.m"
};

static emlrtRTEInfo ub_emlrtRTEI = { 3, 14, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo vb_emlrtRTEI = { 12, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo wb_emlrtRTEI = { 23, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo xb_emlrtRTEI = { 24, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo yb_emlrtRTEI = { 27, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo ac_emlrtRTEI = { 28, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtRTEInfo bc_emlrtRTEI = { 100, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 9, 6, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 9, 6, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  1 };

static emlrtDCInfo l_emlrtDCI = { 10, 6, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  1 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 10, 6, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 13, 20, "DNA.Mpar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtRTEInfo gd_emlrtRTEI = { 31, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 33, 26, "incH", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 34, 20, "DNA.Hpar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 35, 20, "DNA.Hpar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 36, 25, "DNA.Hpar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 39, 15, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 41, 36, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 41, 48, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 41, 60, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 42, 36, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 42, 48, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 42, 60, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 47, 16, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 48, 16, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 50, 36, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 50, 49, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 50, 62, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 51, 36, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 51, 49, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 51, 62, "X", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 53, 31, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 53, 44, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 53, 57, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 54, 31, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 54, 44, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 54, 57, "Xd", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtRTEInfo hd_emlrtRTEI = { 67, 1, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 69, 26, "incS", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 71, 24, "DNA.Spar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 72, 24, "DNA.Spar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 73, 21, "DNA.Spar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 74, 21, "DNA.Spar", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 78, 15, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 79, 24, "comPoint", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 86, 16, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 87, 16, "massnr", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 88, 25, "comPoint", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 89, 25, "comPoint", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 111, 18, "mass", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtECInfo r_emlrtECI = { -1, 114, 5, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m"
};

static emlrtDCInfo m_emlrtDCI = { 27, 12, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  4 };

static emlrtDCInfo n_emlrtDCI = { 28, 12, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  4 };

static emlrtDCInfo o_emlrtDCI = { 100, 16, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  4 };

static emlrtDCInfo p_emlrtDCI = { 109, 12, "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  4 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 111, 5, "Fg", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 103, 9, "Fapply", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 92, 54, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 92, 70, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 92, 86, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 93, 54, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 93, 70, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 93, 86, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 95, 36, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 95, 12, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 96, 36, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 96, 12, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 81, 48, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 81, 63, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 81, 78, "state", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 82, 34, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 82, 12, "Fs", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 57, 36, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 57, 12, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 58, 36, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 58, 12, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 44, 34, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 44, 12, "Fh", "getForces",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getForces.m",
  0 };

/* Function Definitions */
void getForces(const emlrtStack *sp, real_T t, const emxArray_real_T *state,
               const emxArray_real_T *DNA_incstr, const emxArray_real_T
               *DNA_edgelabel, const emxArray_real_T *DNA_Mpar, const
               emxArray_real_T *DNA_Hpar, const emxArray_real_T *DNA_Spar, const
               emxArray_real_T *DNA_Ppar, const emxArray_real_T *DNA_Pmpar,
               emxArray_real_T *F)
{
  real_T y;
  int32_T i38;
  int32_T i39;
  int32_T iv80[2];
  int32_T i40;
  emxArray_real_T *comPoint;
  int32_T iv81[2];
  int32_T i41;
  int32_T i42;
  int32_T i43;
  emxArray_boolean_T *b_DNA_edgelabel;
  int32_T i44;
  int32_T loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  real_T nH;
  emxArray_real_T *incH;
  emxArray_real_T *incS;
  emxArray_real_T *Fs;
  real_T nS;
  int32_T i45;
  emxArray_real_T *Fh;
  int32_T k;
  int32_T ii;
  emxArray_real_T *Fapply;
  boolean_T x_data[100];
  int32_T idx;
  int32_T ii_data[100];
  boolean_T exitg2;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv82[2];
  int32_T massnr_data[100];
  int32_T iv83[2];
  boolean_T b_massnr_data[100];
  int32_T massnr_size[1];
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int32_T b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  real_T MGSF[3];
  real_T b_comPoint[2];
  real_T b_state[3];
  int32_T i46;
  real_T MMSF[6];
  real_T c_state[6];
  real_T massnr;
  real_T dv12[3];
  real_T b_Fs[3];
  real_T dv13[3];
  real_T t3;
  real_T t4;
  int32_T i47;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T d_state[6];
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T MMDT[6];
  real_T t15;
  real_T t2;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t11;
  real_T t22;
  real_T t23;
  real_T t25;
  real_T t30;
  real_T t35;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  nX  = length(state)/2;              %Get the number of coordinates */
  /*  X  = state(1:nX); */
  /*  Xd = state(nX+1:end);               %Get the velocity vector */
  y = (real_T)state->size[0] / 2.0;
  if (1.0 > y) {
    i39 = 0;
  } else {
    i38 = state->size[0];
    if (!(1 <= i38)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i38, &jf_emlrtBCI, sp);
    }

    if (y != muDoubleScalarFloor(y)) {
      emlrtIntegerCheckR2012b(y, &k_emlrtDCI, sp);
    }

    i38 = state->size[0];
    i39 = (int32_T)y;
    if (!(i39 <= i38)) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &jf_emlrtBCI, sp);
    }
  }

  iv80[0] = 1;
  iv80[1] = i39;
  st.site = &kg_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv80);
  y = (real_T)state->size[0] / 2.0;
  if (y + 1.0 > state->size[0]) {
    i40 = 1;
    i38 = 1;
  } else {
    if (y + 1.0 != muDoubleScalarFloor(y + 1.0)) {
      emlrtIntegerCheckR2012b(y + 1.0, &l_emlrtDCI, sp);
    }

    i38 = state->size[0];
    i40 = (int32_T)(y + 1.0);
    if (!((i40 >= 1) && (i40 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i40, 1, i38, &kf_emlrtBCI, sp);
    }

    i38 = state->size[0];
    i41 = state->size[0];
    if (!((i41 >= 1) && (i41 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i41, 1, i38, &kf_emlrtBCI, sp);
    }

    i38 = i41 + 1;
  }

  emxInit_real_T(sp, &comPoint, 2, &vb_emlrtRTEI, true);
  iv81[0] = 1;
  iv81[1] = i38 - i40;
  st.site = &lg_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv81);
  st.site = &mg_emlrtRSI;
  getCompoints(&st, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
               DNA_Ppar, DNA_Pmpar, comPoint);
  if (2 > DNA_Mpar->size[0]) {
    i41 = 0;
    i42 = 1;
  } else {
    i41 = 1;
    i42 = DNA_Mpar->size[0];
    i43 = DNA_Mpar->size[0];
    if (!((i43 >= 1) && (i43 <= i42))) {
      emlrtDynamicBoundsCheckR2012b(i43, 1, i42, &lf_emlrtBCI, sp);
    }

    i42 = i43 + 1;
  }

  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &ub_emlrtRTEI, true);

  /* Mass of bodies */
  i43 = DNA_Mpar->size[0] - 2;
  i44 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i44, (int32_T)
                    sizeof(boolean_T), &ub_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i44 = 0; i44 < loop_ub; i44++) {
    b_DNA_edgelabel->data[i44] = (DNA_edgelabel->data[i44] == 1.0);
  }

  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &ub_emlrtRTEI, true);
  st.site = &ng_emlrtRSI;
  nH = sum(&st, b_DNA_edgelabel);
  i44 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i44, (int32_T)
                    sizeof(boolean_T), &ub_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i44 = 0; i44 < loop_ub; i44++) {
    c_DNA_edgelabel->data[i44] = (DNA_edgelabel->data[i44] == 2.0);
  }

  emxInit_real_T(sp, &incH, 2, &wb_emlrtRTEI, true);
  emxInit_real_T(sp, &incS, 2, &xb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Fs, 1, &yb_emlrtRTEI, true);
  st.site = &og_emlrtRSI;
  nS = sum(&st, c_DNA_edgelabel);

  /* Number of springs */
  st.site = &pg_emlrtRSI;
  b_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incH);
  st.site = &qg_emlrtRSI;
  e_DNA2inc(&st, DNA_incstr, DNA_edgelabel, incS);
  i44 = DNA_Mpar->size[0];
  i45 = Fs->size[0];
  y = 3.0 * ((real_T)i44 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &m_emlrtDCI, sp);
  }

  Fs->size[0] = (int32_T)y;
  emxEnsureCapacity(sp, (emxArray__common *)Fs, i45, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  y = 3.0 * ((real_T)i44 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &m_emlrtDCI, sp);
  }

  loop_ub = (int32_T)y;
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i44 = 0; i44 < loop_ub; i44++) {
    Fs->data[i44] = 0.0;
  }

  emxInit_real_T1(sp, &Fh, 1, &ac_emlrtRTEI, true);
  i44 = DNA_Mpar->size[0];
  i45 = Fh->size[0];
  y = 3.0 * ((real_T)i44 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &n_emlrtDCI, sp);
  }

  Fh->size[0] = (int32_T)y;
  emxEnsureCapacity(sp, (emxArray__common *)Fh, i45, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  y = 3.0 * ((real_T)i44 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &n_emlrtDCI, sp);
  }

  loop_ub = (int32_T)y;
  for (i44 = 0; i44 < loop_ub; i44++) {
    Fh->data[i44] = 0.0;
  }

  /* Set torsion springs and hinge friction */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nH, mxDOUBLE_CLASS, (int32_T)nH,
    &gd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nH - 1) {
    st.site = &rg_emlrtRSI;
    loop_ub = incH->size[0];
    i44 = incH->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i44))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i44, &mf_emlrtBCI, &st);
    }

    ii = k + 1;
    for (i44 = 0; i44 < loop_ub; i44++) {
      x_data[i44] = (incH->data[i44 + incH->size[0] * (ii - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= loop_ub) {
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

    if (idx <= loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (loop_ub == 1) {
      if (idx == 0) {
        loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i44 = 0;
      } else {
        i44 = idx;
      }

      iv82[0] = 1;
      iv82[1] = i44;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, loop_ub, iv82);
      loop_ub = i44;
    }

    for (i44 = 0; i44 < loop_ub; i44++) {
      massnr_data[i44] = ii_data[i44];
    }

    i44 = DNA_Hpar->size[1];
    i45 = k + 1;
    if (!((i45 >= 1) && (i45 <= i44))) {
      emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &nf_emlrtBCI, sp);
    }

    i44 = DNA_Hpar->size[1];
    i45 = k + 1;
    if (!((i45 >= 1) && (i45 <= i44))) {
      emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &of_emlrtBCI, sp);
    }

    i44 = DNA_Hpar->size[1];
    i45 = k + 1;
    if (!((i45 >= 1) && (i45 <= i44))) {
      emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &pf_emlrtBCI, sp);
    }

    massnr_size[0] = loop_ub;
    for (i44 = 0; i44 < loop_ub; i44++) {
      b_massnr_data[i44] = (massnr_data[i44] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int32_T *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    st.site = &sg_emlrtRSI;
    if (any(&st, &c_massnr_data)) {
      if (!(2 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &qf_emlrtBCI, sp);
      }

      /* account for ground */
      i44 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((i44 >= 1) && (i44 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i44, 1, i39, &rf_emlrtBCI, sp);
      }

      i44 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((i44 >= 1) && (i44 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i44, 1, i39, &sf_emlrtBCI, sp);
      }

      i44 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i44 >= 1) && (i44 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i44, 1, i39, &tf_emlrtBCI, sp);
      }

      i44--;
      MGSF[2] = state->data[i44];

      /* MGTORSION */
      /*     FT1 = MGTORSION(K,THETA0,IN3) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:25 */
      /* Torsion Spring */
      i44 = i38 - i40;
      i45 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((i45 >= 1) && (i45 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &uf_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      i45 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((i45 >= 1) && (i45 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &vf_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      i45 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i45 >= 1) && (i45 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &wf_emlrtBCI, sp);
      }

      y = state->data[(i40 + i45) - 2];

      /* MGTORSION */
      /*     FT1 = MGTORSION(K,THETA0,IN3) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:25 */
      /* Hinge Damping */
      massnr = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Fh->size[0];
      dv12[0] = 0.0;
      dv12[1] = 0.0;
      dv12[2] = DNA_Hpar->data[2 + DNA_Hpar->size[0] * k] * (DNA_Hpar->data[4 +
        DNA_Hpar->size[0] * k] * 2.0 - MGSF[2] * 2.0) * 0.5;
      dv13[0] = 0.0;
      dv13[1] = 0.0;
      dv13[2] = DNA_Hpar->data[3 + DNA_Hpar->size[0] * k] * (DNA_Hpar->data[4 +
        DNA_Hpar->size[0] * k] * 2.0 - y * 2.0) * 0.5;
      y = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = Fh->size[0];
      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(massnr + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, idx, &uh_emlrtBCI, sp);
        }

        b_Fs[i44] = (Fh->data[i45 - 1] + dv12[i44]) + dv13[i44];
      }

      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(y + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, ii, &vh_emlrtBCI, sp);
        }

        Fh->data[i45 - 1] = b_Fs[i44];
      }
    } else {
      if (!(1 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &xf_emlrtBCI, sp);
      }

      if (!(2 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &yf_emlrtBCI, sp);
      }

      /* Torsion spring */
      i44 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 2.0);
      if (!((i44 >= 1) && (i44 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i44, 1, i39, &ag_emlrtBCI, sp);
      }

      i44--;
      i45 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 1.0);
      if (!((i45 >= 1) && (i45 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i39, &bg_emlrtBCI, sp);
      }

      i45--;
      idx = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0);
      if (!((idx >= 1) && (idx <= i39))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i39, &cg_emlrtBCI, sp);
      }

      idx--;
      ii = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((ii >= 1) && (ii <= i39))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i39, &dg_emlrtBCI, sp);
      }

      ii--;
      loop_ub = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((loop_ub >= 1) && (loop_ub <= i39))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i39, &eg_emlrtBCI, sp);
      }

      loop_ub--;
      i46 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i46 >= 1) && (i46 <= i39))) {
        emlrtDynamicBoundsCheckR2012b(i46, 1, i39, &fg_emlrtBCI, sp);
      }

      i46--;
      c_state[0] = state->data[i44];
      c_state[1] = state->data[i45];
      c_state[2] = state->data[idx];
      c_state[3] = state->data[ii];
      c_state[4] = state->data[loop_ub];
      c_state[5] = state->data[i46];
      MMtorsion(DNA_Hpar->data[2 + DNA_Hpar->size[0] * k], DNA_Hpar->data[4 +
                DNA_Hpar->size[0] * k], c_state, MMSF);

      /* Hinge Damping */
      i44 = i38 - i40;
      i45 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 2.0);
      if (!((i45 >= 1) && (i45 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i45, 1, i44, &gg_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      idx = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 1.0);
      if (!((idx >= 1) && (idx <= i44))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i44, &hg_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      ii = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0);
      if (!((ii >= 1) && (ii <= i44))) {
        emlrtDynamicBoundsCheckR2012b(ii, 1, i44, &ig_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      loop_ub = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((loop_ub >= 1) && (loop_ub <= i44))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i44, &jg_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      i46 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((i46 >= 1) && (i46 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i46, 1, i44, &kg_emlrtBCI, sp);
      }

      i44 = i38 - i40;
      i47 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i47 >= 1) && (i47 <= i44))) {
        emlrtDynamicBoundsCheckR2012b(i47, 1, i44, &lg_emlrtBCI, sp);
      }

      d_state[0] = state->data[(i40 + i45) - 2];
      d_state[1] = state->data[(i40 + idx) - 2];
      d_state[2] = state->data[(i40 + ii) - 2];
      d_state[3] = state->data[(i40 + loop_ub) - 2];
      d_state[4] = state->data[(i40 + i46) - 2];
      d_state[5] = state->data[(i40 + i47) - 2];
      MMtorsion(DNA_Hpar->data[3 + DNA_Hpar->size[0] * k], 0.0, d_state, MMDT);
      massnr = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = Fh->size[0];
      y = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ii = Fh->size[0];
      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(massnr + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, idx, &qh_emlrtBCI, sp);
        }

        b_Fs[i44] = (Fh->data[i45 - 1] + MMSF[i44]) + MMDT[i44];
      }

      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(y + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, ii, &rh_emlrtBCI, sp);
        }

        Fh->data[i45 - 1] = b_Fs[i44];
      }

      massnr = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Fh->size[0];
      y = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = Fh->size[0];
      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(massnr + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, idx, &sh_emlrtBCI, sp);
        }

        b_Fs[i44] = (Fh->data[i45 - 1] + MMSF[3 + i44]) + MMDT[3 + i44];
      }

      for (i44 = 0; i44 < 3; i44++) {
        i45 = (int32_T)(y + (-2.0 + (real_T)i44));
        if (!((i45 >= 1) && (i45 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i45, 1, ii, &th_emlrtBCI, sp);
        }

        Fh->data[i45 - 1] = b_Fs[i44];
      }

      /*          Fh(mnr2*3,1) = -(X(mnr2*3)-X(mnr1*3))*DNA.Hpar(3,k)-(Xd(mnr2*3)-Xd(mnr1*3))*DNA.Hpar(4,k); */
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incH);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nS, mxDOUBLE_CLASS, (int32_T)nS,
    &hd_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nS - 1) {
    st.site = &tg_emlrtRSI;
    loop_ub = incS->size[0];
    i38 = incS->size[1];
    if (!((k + 1 >= 1) && (k + 1 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i38, &mg_emlrtBCI, &st);
    }

    ii = k + 1;
    for (i38 = 0; i38 < loop_ub; i38++) {
      x_data[i38] = (incS->data[i38 + incS->size[0] * (ii - 1)] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= loop_ub) {
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

    if (idx <= loop_ub) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (loop_ub == 1) {
      if (idx == 0) {
        loop_ub = 0;
      }
    } else {
      if (1 > idx) {
        i38 = 0;
      } else {
        i38 = idx;
      }

      iv83[0] = 1;
      iv83[1] = i38;
      c_st.site = &nb_emlrtRSI;
      indexShapeCheck(&c_st, loop_ub, iv83);
      loop_ub = i38;
    }

    for (i38 = 0; i38 < loop_ub; i38++) {
      massnr_data[i38] = ii_data[i38];
    }

    /* Find entries in column */
    i38 = DNA_Spar->size[1];
    i39 = k + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &ng_emlrtBCI, sp);
    }

    i38 = DNA_Spar->size[1];
    i39 = k + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &og_emlrtBCI, sp);
    }

    i38 = DNA_Spar->size[1];
    i39 = k + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &pg_emlrtBCI, sp);
    }

    i38 = DNA_Spar->size[1];
    i39 = k + 1;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &qg_emlrtBCI, sp);
    }

    b_massnr_size[0] = loop_ub;
    for (i38 = 0; i38 < loop_ub; i38++) {
      d_massnr_data[i38] = (massnr_data[i38] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int32_T *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    st.site = &ug_emlrtRSI;
    if (any(&st, &e_massnr_data)) {
      /* account for ground */
      if (!(2 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &rg_emlrtBCI, sp);
      }

      i38 = comPoint->size[0];
      i39 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &sg_emlrtBCI, sp);
      }

      for (i38 = 0; i38 < 2; i38++) {
        b_comPoint[i38] = comPoint->data[((int32_T)((real_T)massnr_data[1] - 1.0)
          + comPoint->size[0] * i38) - 1];
      }

      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &lh_emlrtBCI, sp);
      }

      b_state[0] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &mh_emlrtBCI, sp);
      }

      b_state[1] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &nh_emlrtBCI, sp);
      }

      b_state[2] = state->data[i39 - 1];
      st.site = &vg_emlrtRSI;
      MGspringforce(&st, *(real_T (*)[2])&DNA_Spar->data[DNA_Spar->size[0] * k],
                    *(real_T (*)[2])&DNA_Spar->data[2 + DNA_Spar->size[0] * k],
                    DNA_Spar->data[4 + DNA_Spar->size[0] * k], DNA_Spar->data[5
                    + DNA_Spar->size[0] * k], b_comPoint, b_state, MGSF);
      massnr = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = Fs->size[0];
      y = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Fs->size[0];
      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(massnr + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, ii, &oh_emlrtBCI, sp);
        }

        b_Fs[i38] = Fs->data[i39 - 1] + MGSF[i38];
      }

      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(y + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, idx, &ph_emlrtBCI, sp);
        }

        Fs->data[i39 - 1] = b_Fs[i38];
      }
    } else {
      if (!(1 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &tg_emlrtBCI, sp);
      }

      if (!(2 <= loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &ug_emlrtBCI, sp);
      }

      i38 = comPoint->size[0];
      i39 = (int32_T)((real_T)massnr_data[0] - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &vg_emlrtBCI, sp);
      }

      i38 = comPoint->size[0];
      i39 = (int32_T)((real_T)massnr_data[1] - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &wg_emlrtBCI, sp);
      }

      st.site = &wg_emlrtRSI;
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 2.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &bh_emlrtBCI, &st);
      }

      MMSF[0] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0 - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &ch_emlrtBCI, &st);
      }

      MMSF[1] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[0] - 1.0) * 3.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &dh_emlrtBCI, &st);
      }

      MMSF[2] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 2.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &eh_emlrtBCI, &st);
      }

      MMSF[3] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0 - 1.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &fh_emlrtBCI, &st);
      }

      MMSF[4] = state->data[i39 - 1];
      i38 = state->size[0];
      i39 = (int32_T)(((real_T)massnr_data[1] - 1.0) * 3.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &gh_emlrtBCI, &st);
      }

      MMSF[5] = state->data[i39 - 1];

      /* MMSPRINGFORCE */
      /*     FS2 = MMSPRINGFORCE(IN1,IN2,L0,K,IN5,IN6,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     17-Oct-2016 18:51:24 */
      t3 = muDoubleScalarCos(MMSF[2]);
      t4 = comPoint->data[((int32_T)((real_T)massnr_data[0] - 1.0) +
                           comPoint->size[0]) - 1] - DNA_Spar->data[1 +
        DNA_Spar->size[0] * k];
      t5 = muDoubleScalarCos(MMSF[5]);
      t6 = comPoint->data[((int32_T)((real_T)massnr_data[1] - 1.0) +
                           comPoint->size[0]) - 1] - DNA_Spar->data[3 +
        DNA_Spar->size[0] * k];
      t7 = muDoubleScalarSin(MMSF[2]);
      t8 = comPoint->data[(int32_T)((real_T)massnr_data[0] - 1.0) - 1] -
        DNA_Spar->data[DNA_Spar->size[0] * k];
      t9 = muDoubleScalarSin(MMSF[5]);
      t10 = comPoint->data[(int32_T)((real_T)massnr_data[1] - 1.0) - 1] -
        DNA_Spar->data[2 + DNA_Spar->size[0] * k];
      t12 = t3 * t8;
      t13 = t5 * t10;
      t14 = t4 * t7;
      t15 = t6 * t9;
      t2 = ((((-t12 + t13) + t14) - t15) + MMSF[0]) - MMSF[3];
      t17 = t3 * t4;
      t18 = t5 * t6;
      t19 = t7 * t8;
      t20 = t9 * t10;
      t11 = ((((-t17 + t18) - t19) + t20) + MMSF[1]) - MMSF[4];
      b_st.site = &dh_emlrtRSI;
      b_st.site = &eh_emlrtRSI;
      t22 = t2 * t2 + t11 * t11;
      b_st.site = &fh_emlrtRSI;
      if (t22 < 0.0) {
        c_st.site = &gf_emlrtRSI;
        e_error(&c_st);
      }

      t23 = 1.0 / muDoubleScalarSqrt(t22);
      b_st.site = &gh_emlrtRSI;
      t25 = DNA_Spar->data[4 + DNA_Spar->size[0] * k] - muDoubleScalarSqrt(t22);
      t30 = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (((((MMSF[0]
        * 2.0 + t5 * t10 * 2.0) + t4 * t7 * 2.0) - MMSF[3] * 2.0) - t3 * t8 *
        2.0) - t6 * t9 * 2.0) * 0.5;
      t35 = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (((((MMSF[1]
        * 2.0 + t5 * t6 * 2.0) + t9 * t10 * 2.0) - MMSF[4] * 2.0) - t3 * t4 *
        2.0) - t7 * t8 * 2.0) * 0.5;
      MMSF[0] = t30;
      MMSF[1] = t35;
      MMSF[2] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (t2 *
        (t17 + t19) * 2.0 - t11 * (t12 - t14) * 2.0) * 0.5;
      MMSF[3] = -t30;
      MMSF[4] = -t35;
      MMSF[5] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (t2 *
        (t18 + t20) * 2.0 - t11 * (t13 - t15) * 2.0) * -0.5;
      massnr = ((real_T)massnr_data[0] - 1.0) * 3.0;
      ii = Fs->size[0];
      y = ((real_T)massnr_data[0] - 1.0) * 3.0;
      idx = Fs->size[0];
      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(massnr + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, ii, &hh_emlrtBCI, sp);
        }

        b_Fs[i38] = Fs->data[i39 - 1] + MMSF[i38];
      }

      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(y + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, idx, &ih_emlrtBCI, sp);
        }

        Fs->data[i39 - 1] = b_Fs[i38];
      }

      massnr = ((real_T)massnr_data[1] - 1.0) * 3.0;
      ii = Fs->size[0];
      y = ((real_T)massnr_data[1] - 1.0) * 3.0;
      idx = Fs->size[0];
      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(massnr + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= ii))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, ii, &jh_emlrtBCI, sp);
        }

        b_Fs[i38] = Fs->data[i39 - 1] + MMSF[3 + i38];
      }

      for (i38 = 0; i38 < 3; i38++) {
        i39 = (int32_T)(y + (-2.0 + (real_T)i38));
        if (!((i39 >= 1) && (i39 <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i39, 1, idx, &kh_emlrtBCI, sp);
        }

        Fs->data[i39 - 1] = b_Fs[i38];
      }
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&incS);
  emxFree_real_T(&comPoint);
  emxInit_real_T1(sp, &Fapply, 1, &bc_emlrtRTEI, true);
  i38 = DNA_Mpar->size[0];
  i39 = Fapply->size[0];
  y = 3.0 * ((real_T)i38 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &o_emlrtDCI, sp);
  }

  Fapply->size[0] = (int32_T)y;
  emxEnsureCapacity(sp, (emxArray__common *)Fapply, i39, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  y = 3.0 * ((real_T)i38 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &o_emlrtDCI, sp);
  }

  loop_ub = (int32_T)y;
  for (i38 = 0; i38 < loop_ub; i38++) {
    Fapply->data[i38] = 0.0;
  }

  if ((2.0 < t) && (t < 4.0)) {
    k = 0;
    while (k <= i43) {
      i38 = Fapply->size[0];
      i39 = (int32_T)((1.0 + (real_T)k) * 3.0);
      if (!((i39 >= 1) && (i39 <= i38))) {
        emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &ah_emlrtBCI, sp);
      }

      Fapply->data[i39 - 1] = 0.0;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  i38 = DNA_Mpar->size[0];
  i39 = F->size[0];
  y = 3.0 * ((real_T)i38 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &p_emlrtDCI, sp);
  }

  F->size[0] = (int32_T)y;
  emxEnsureCapacity(sp, (emxArray__common *)F, i39, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  y = 3.0 * ((real_T)i38 - 1.0);
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &p_emlrtDCI, sp);
  }

  loop_ub = (int32_T)y;
  for (i38 = 0; i38 < loop_ub; i38++) {
    F->data[i38] = 0.0;
  }

  k = 0;
  while (k <= i43) {
    i38 = (i42 - i41) - 1;
    i39 = 1 + k;
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &xg_emlrtBCI, sp);
    }

    i38 = F->size[0];
    i39 = (int32_T)((1.0 + (real_T)k) * 3.0 - 1.0);
    if (!((i39 >= 1) && (i39 <= i38))) {
      emlrtDynamicBoundsCheckR2012b(i39, 1, i38, &yg_emlrtBCI, sp);
    }

    F->data[i39 - 1] = -DNA_Mpar->data[(i41 + k) + (DNA_Mpar->size[0] << 1)] *
      9.81;
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i38 = F->size[0];
  i39 = Fs->size[0];
  if (i38 != i39) {
    emlrtSizeEqCheck1DR2012b(i38, i39, &r_emlrtECI, sp);
  }

  i38 = F->size[0];
  i39 = Fh->size[0];
  if (i38 != i39) {
    emlrtSizeEqCheck1DR2012b(i38, i39, &r_emlrtECI, sp);
  }

  i38 = F->size[0];
  i39 = Fapply->size[0];
  if (i38 != i39) {
    emlrtSizeEqCheck1DR2012b(i38, i39, &r_emlrtECI, sp);
  }

  i38 = F->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)F, i38, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  loop_ub = F->size[0];
  for (i38 = 0; i38 < loop_ub; i38++) {
    F->data[i38] = ((F->data[i38] + Fs->data[i38]) + Fh->data[i38]) +
      Fapply->data[i38];
  }

  emxFree_real_T(&Fapply);
  emxFree_real_T(&Fh);
  emxFree_real_T(&Fs);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (getForces.c) */
