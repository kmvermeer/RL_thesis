/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCompoints.c
 *
 * Code generation for function 'getCompoints'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getCompoints.h"
#include "simulateDNA_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "DNA2inc.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 76, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo e_emlrtRSI = { 70, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo f_emlrtRSI = { 65, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo g_emlrtRSI = { 53, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo h_emlrtRSI = { 52, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo i_emlrtRSI = { 48, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo j_emlrtRSI = { 36, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo k_emlrtRSI = { 32, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo l_emlrtRSI = { 24, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo m_emlrtRSI = { 23, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo n_emlrtRSI = { 19, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo o_emlrtRSI = { 11, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRSInfo p_emlrtRSI = { 7, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 3, 21, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 253, 13, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 7, 1, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 11, 5, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 12, 5, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 15, 9, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 24, 13, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 36, 6, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtBCInfo e_emlrtBCI = { -1, -1, 76, 18, "comPoint", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 40, 18, "comPoint", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 71, 24, "points", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 66, 25, "points", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 60, 28, "points", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 57, 28, "points", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 49, 24, "points", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 71, 46, "DNA.Pmpar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 70, 29, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 70, 45, "edgeIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 66, 46, "DNA.Ppar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 65, 29, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 65, 45, "edgeIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 60, 49, "DNA.Spar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 58, 29, "vrtxIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 57, 49, "DNA.Spar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 55, 25, "vrtxIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 53, 28, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 53, 44, "edgeIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 52, 38, "inc", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 49, 45, "DNA.Hpar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 48, 28, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 48, 44, "edgeIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 37, 41, "DNA.Pmpar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 36, 25, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 33, 40, "DNA.Ppar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 32, 24, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 28, 44, "DNA.Spar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 27, 23, "vrtxIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 26, 44, "DNA.Spar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 25, 19, "vrtxIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 23, 24, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 20, 40, "DNA.Hpar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 19, 31, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 16, 32, "DNA.Mpar", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 11, 28, "inc", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtDCInfo emlrtDCI = { 6, 21, "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  4 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 12, 19, "DNA.edgelabel",
  "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 47, 16, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 51, 20, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 63, 20, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 68, 20, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 70, 59, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 65, 59, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 52, 38, "edgeIdx", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 53, 58, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 48, 58, "edgelabel", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 24, 34, "inc", "getCompoints",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getCompoints.m",
  0 };

/* Function Definitions */
void getCompoints(const emlrtStack *sp, const emxArray_real_T *DNA_incstr, const
                  emxArray_real_T *DNA_edgelabel, const emxArray_real_T
                  *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
                  emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
                  const emxArray_real_T *DNA_Pmpar, emxArray_real_T *comPoint)
{
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T nx;
  int32_T loop_ub;
  emxArray_real_T *inc;
  int32_T k;
  emxArray_real_T *edgeIdx;
  emxArray_real_T *edgelabel;
  emxArray_real_T *points;
  emxArray_real_T *vrtxIdx;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *b_ii;
  emxArray_boolean_T *b_DNA_edgelabel;
  emxArray_boolean_T *c_DNA_edgelabel;
  emxArray_boolean_T *d_DNA_edgelabel;
  emxArray_boolean_T *e_DNA_edgelabel;
  emxArray_boolean_T *f_DNA_edgelabel;
  emxArray_boolean_T *g_DNA_edgelabel;
  emxArray_boolean_T *h_DNA_edgelabel;
  emxArray_boolean_T *i_DNA_edgelabel;
  int32_T idx;
  boolean_T overflow;
  int32_T c_ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  real_T b_points[4];
  real_T dv1[2];
  real_T b_edgelabel;
  real_T Hidx;
  boolean_T x_data[100];
  real_T Sidx;
  real_T Pmidx;
  real_T Pidx;
  int32_T ii_data[100];
  boolean_T exitg1;
  int32_T b_loop_ub;
  boolean_T guard1 = false;
  int32_T iv0[2];
  int32_T i_data[100];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv1[2];
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
  i2 = DNA_Mpar->size[0];

  /* Number of masses */
  i3 = DNA_Mpar->size[0];
  i4 = comPoint->size[0] * comPoint->size[1];
  nx = i3 - 1;
  if (!(nx >= 0)) {
    emlrtNonNegativeCheckR2012b(nx, &emlrtDCI, sp);
  }

  comPoint->size[0] = nx;
  comPoint->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)comPoint, i4, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  i3--;
  if (!(i3 >= 0)) {
    emlrtNonNegativeCheckR2012b(i3, &emlrtDCI, sp);
  }

  loop_ub = i3 << 1;
  for (i3 = 0; i3 < loop_ub; i3++) {
    comPoint->data[i3] = 0.0;
  }

  emxInit_real_T(sp, &inc, 2, &f_emlrtRTEI, true);

  /* Initialize compoint array */
  st.site = &p_emlrtRSI;
  DNA2inc(&st, DNA_incstr, inc);
  k = 0;
  emxInit_real_T(sp, &edgeIdx, 2, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &edgelabel, 2, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &points, 2, &i_emlrtRTEI, true);
  emxInit_real_T1(sp, &vrtxIdx, 1, &j_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 2, &d_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 2, &k_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_x, 2, &d_emlrtRTEI, true);
  emxInit_int32_T1(sp, &b_ii, 1, &k_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &c_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &d_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &e_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &f_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &g_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &h_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  emxInit_boolean_T(sp, &i_DNA_edgelabel, 2, &d_emlrtRTEI, true);
  while (k <= i2 - 2) {
    /* for all masses */
    st.site = &o_emlrtRSI;
    loop_ub = inc->size[1];
    i3 = inc->size[0];
    i4 = 2 + k;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &ob_emlrtBCI, &st);
    }

    i3 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity(&st, (emxArray__common *)x, i3, (int32_T)sizeof(boolean_T),
                      &d_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      x->data[x->size[0] * i3] = (inc->data[(i4 + inc->size[0] * i3) - 1] == 1.0);
    }

    b_st.site = &lb_emlrtRSI;
    nx = x->size[1];
    idx = 0;
    i3 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                      &d_emlrtRTEI);
    c_st.site = &mb_emlrtRSI;
    overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    c_ii = 1;
    exitg3 = false;
    while ((!exitg3) && (c_ii <= nx)) {
      guard3 = false;
      if (x->data[c_ii - 1]) {
        idx++;
        ii->data[idx - 1] = c_ii;
        if (idx >= nx) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        c_ii++;
      }
    }

    if (idx <= x->size[1]) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[1] == 1) {
      if (idx == 0) {
        i3 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof
                          (int32_T), &d_emlrtRTEI);
      }
    } else {
      i3 = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof
                        (int32_T), &e_emlrtRTEI);
    }

    i3 = edgeIdx->size[0] * edgeIdx->size[1];
    edgeIdx->size[0] = 1;
    edgeIdx->size[1] = ii->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)edgeIdx, i3, (int32_T)sizeof
                      (real_T), &d_emlrtRTEI);
    loop_ub = ii->size[0] * ii->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      edgeIdx->data[i3] = ii->data[i3];
    }

    /* verbonden edges per mass */
    i3 = edgelabel->size[0] * edgelabel->size[1];
    edgelabel->size[0] = 1;
    edgelabel->size[1] = edgeIdx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)edgelabel, i3, (int32_T)sizeof
                      (real_T), &d_emlrtRTEI);
    nx = DNA_edgelabel->size[1];
    loop_ub = edgeIdx->size[0] * edgeIdx->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      i4 = (int32_T)edgeIdx->data[i3];
      if (!((i4 >= 1) && (i4 <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, nx, &pb_emlrtBCI, sp);
      }

      edgelabel->data[i3] = DNA_edgelabel->data[i4 - 1];
    }

    if (edgeIdx->size[1] == 1) {
      /* If there is only one edge */
      for (i3 = 0; i3 < 4; i3++) {
        b_points[i3] = 0.0;
      }

      /* Empty point array  */
      i3 = DNA_Mpar->size[0];
      i4 = 2 + k;
      if (!((i4 >= 1) && (i4 <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &nb_emlrtBCI, sp);
      }

      for (i3 = 0; i3 < 2; i3++) {
        b_points[i3 << 1] = DNA_Mpar->data[(i4 + DNA_Mpar->size[0] * i3) - 1];
      }

      /* Get first point out of mass data */
      if (DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1] == 1.0) {
        /* for hinge               %If connection is hinge */
        i3 = DNA_edgelabel->size[1];
        if (!(1 <= i3)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i3, &mb_emlrtBCI, sp);
        }

        i3 = DNA_edgelabel->size[1];
        i4 = (int32_T)edgeIdx->data[0];
        if (!((i4 >= 1) && (i4 <= i3))) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &mb_emlrtBCI, sp);
        }

        loop_ub = (int32_T)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1];
        i3 = i_DNA_edgelabel->size[0] * i_DNA_edgelabel->size[1];
        i_DNA_edgelabel->size[0] = 1;
        i_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)i_DNA_edgelabel, i3, (int32_T)
                          sizeof(boolean_T), &d_emlrtRTEI);
        for (i3 = 0; i3 < loop_ub; i3++) {
          i_DNA_edgelabel->data[i_DNA_edgelabel->size[0] * i3] =
            (DNA_edgelabel->data[i3] == b_edgelabel);
        }

        st.site = &n_emlrtRSI;
        Hidx = sum(&st, i_DNA_edgelabel);
        i3 = DNA_Hpar->size[1];
        nx = (int32_T)Hidx;
        if (!((nx >= 1) && (nx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &lb_emlrtBCI, sp);
        }

        for (i3 = 0; i3 < 2; i3++) {
          b_points[1 + (i3 << 1)] = DNA_Hpar->data[i3 + DNA_Hpar->size[0] * (nx
            - 1)];
        }
      } else if (DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1] == 2.0) {
        /* for spring */
        i3 = DNA_edgelabel->size[1];
        if (!(1 <= i3)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i3, &kb_emlrtBCI, sp);
        }

        i3 = DNA_edgelabel->size[1];
        i4 = (int32_T)edgeIdx->data[0];
        if (!((i4 >= 1) && (i4 <= i3))) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &kb_emlrtBCI, sp);
        }

        loop_ub = (int32_T)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1];
        i3 = h_DNA_edgelabel->size[0] * h_DNA_edgelabel->size[1];
        h_DNA_edgelabel->size[0] = 1;
        h_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)h_DNA_edgelabel, i3, (int32_T)
                          sizeof(boolean_T), &d_emlrtRTEI);
        for (i3 = 0; i3 < loop_ub; i3++) {
          h_DNA_edgelabel->data[h_DNA_edgelabel->size[0] * i3] =
            (DNA_edgelabel->data[i3] == b_edgelabel);
        }

        st.site = &m_emlrtRSI;
        Sidx = sum(&st, h_DNA_edgelabel);
        st.site = &l_emlrtRSI;
        loop_ub = inc->size[0];
        idx = inc->size[1];
        i3 = b_x->size[0] * b_x->size[1];
        b_x->size[0] = loop_ub;
        b_x->size[1] = edgeIdx->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)b_x, i3, (int32_T)sizeof
                          (boolean_T), &d_emlrtRTEI);
        b_loop_ub = edgeIdx->size[1];
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          for (i4 = 0; i4 < loop_ub; i4++) {
            nx = (int32_T)edgeIdx->data[edgeIdx->size[0] * i3];
            if (!((nx >= 1) && (nx <= idx))) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, idx, &ac_emlrtBCI, &st);
            }

            b_x->data[i4 + b_x->size[0] * i3] = (inc->data[i4 + inc->size[0] *
              (nx - 1)] == 1.0);
          }
        }

        b_st.site = &lb_emlrtRSI;
        nx = b_x->size[0];
        idx = 0;
        i3 = b_ii->size[0];
        b_ii->size[0] = nx;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i3, (int32_T)sizeof
                          (int32_T), &d_emlrtRTEI);
        c_st.site = &mb_emlrtRSI;
        c_ii = 1;
        exitg2 = false;
        while ((!exitg2) && (c_ii <= nx)) {
          guard2 = false;
          if (b_x->data[c_ii - 1]) {
            idx++;
            b_ii->data[idx - 1] = c_ii;
            if (idx >= nx) {
              exitg2 = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2) {
            c_ii++;
          }
        }

        if (idx <= nx) {
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
            "Coder:builtins:AssertionFailed", 0);
        }

        if (nx == 1) {
          if (idx == 0) {
            i3 = b_ii->size[0];
            b_ii->size[0] = 0;
            emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i3, (int32_T)
                              sizeof(int32_T), &d_emlrtRTEI);
          }
        } else {
          if (1 > idx) {
            i3 = 0;
          } else {
            i3 = idx;
          }

          iv1[0] = 1;
          iv1[1] = i3;
          c_st.site = &nb_emlrtRSI;
          indexShapeCheck(&c_st, b_ii->size[0], iv1);
          i4 = b_ii->size[0];
          b_ii->size[0] = i3;
          emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i4, (int32_T)sizeof
                            (int32_T), &e_emlrtRTEI);
        }

        i3 = vrtxIdx->size[0];
        vrtxIdx->size[0] = b_ii->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)vrtxIdx, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = b_ii->size[0];
        for (i3 = 0; i3 < loop_ub; i3++) {
          vrtxIdx->data[i3] = b_ii->data[i3];
        }

        i3 = vrtxIdx->size[0];
        if (!(1 <= i3)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i3, &jb_emlrtBCI, sp);
        }

        if (1.0 + (real_T)k == vrtxIdx->data[0] - 1.0) {
          i3 = DNA_Spar->size[1];
          nx = (int32_T)Sidx;
          if (!((nx >= 1) && (nx <= i3))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &ib_emlrtBCI, sp);
          }

          for (i3 = 0; i3 < 2; i3++) {
            b_points[1 + (i3 << 1)] = DNA_Spar->data[i3 + DNA_Spar->size[0] *
              (nx - 1)];
          }
        } else {
          i3 = vrtxIdx->size[0];
          if (!(2 <= i3)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i3, &hb_emlrtBCI, sp);
          }

          if (1.0 + (real_T)k == vrtxIdx->data[1] - 1.0) {
            i3 = DNA_Spar->size[1];
            nx = (int32_T)Sidx;
            if (!((nx >= 1) && (nx <= i3))) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &gb_emlrtBCI, sp);
            }

            for (i3 = 0; i3 < 2; i3++) {
              b_points[1 + (i3 << 1)] = DNA_Spar->data[(i3 + DNA_Spar->size[0] *
                (nx - 1)) + 2];
            }
          }
        }
      } else if (DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1] == 3.0) {
        /* for prismatic joint */
        i3 = DNA_edgelabel->size[1];
        if (!(1 <= i3)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i3, &fb_emlrtBCI, sp);
        }

        i3 = DNA_edgelabel->size[1];
        i4 = (int32_T)edgeIdx->data[0];
        if (!((i4 >= 1) && (i4 <= i3))) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &fb_emlrtBCI, sp);
        }

        loop_ub = (int32_T)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1];
        i3 = g_DNA_edgelabel->size[0] * g_DNA_edgelabel->size[1];
        g_DNA_edgelabel->size[0] = 1;
        g_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)g_DNA_edgelabel, i3, (int32_T)
                          sizeof(boolean_T), &d_emlrtRTEI);
        for (i3 = 0; i3 < loop_ub; i3++) {
          g_DNA_edgelabel->data[g_DNA_edgelabel->size[0] * i3] =
            (DNA_edgelabel->data[i3] == b_edgelabel);
        }

        st.site = &k_emlrtRSI;
        Pidx = sum(&st, g_DNA_edgelabel);
        i3 = DNA_Ppar->size[1];
        nx = (int32_T)Pidx;
        if (!((nx >= 1) && (nx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &eb_emlrtBCI, sp);
        }

        for (i3 = 0; i3 < 2; i3++) {
          b_points[1 + (i3 << 1)] = DNA_Ppar->data[i3 + DNA_Ppar->size[0] * (nx
            - 1)];
        }
      } else {
        if (DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1] == 4.0) {
          i3 = DNA_edgelabel->size[1];
          if (!(1 <= i3)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &db_emlrtBCI, sp);
          }

          i3 = DNA_edgelabel->size[1];
          i4 = (int32_T)edgeIdx->data[0];
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &db_emlrtBCI, sp);
          }

          loop_ub = (int32_T)edgeIdx->data[0];
          b_edgelabel = DNA_edgelabel->data[(int32_T)edgeIdx->data[0] - 1];
          i3 = f_DNA_edgelabel->size[0] * f_DNA_edgelabel->size[1];
          f_DNA_edgelabel->size[0] = 1;
          f_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity(sp, (emxArray__common *)f_DNA_edgelabel, i3,
                            (int32_T)sizeof(boolean_T), &d_emlrtRTEI);
          for (i3 = 0; i3 < loop_ub; i3++) {
            f_DNA_edgelabel->data[f_DNA_edgelabel->size[0] * i3] =
              (DNA_edgelabel->data[i3] == b_edgelabel);
          }

          st.site = &j_emlrtRSI;
          Pmidx = sum(&st, f_DNA_edgelabel);
          i3 = DNA_Pmpar->size[1];
          nx = (int32_T)Pmidx;
          if (!((nx >= 1) && (nx <= i3))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &cb_emlrtBCI, sp);
          }

          for (i3 = 0; i3 < 2; i3++) {
            b_points[1 + (i3 << 1)] = DNA_Pmpar->data[i3 + DNA_Pmpar->size[0] *
              (nx - 1)];
          }
        }
      }

      mean(b_points, dv1);
      nx = comPoint->size[0];
      i3 = 1 + k;
      if (!((i3 >= 1) && (i3 <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, nx, &f_emlrtBCI, sp);
      }

      for (i3 = 0; i3 < 2; i3++) {
        comPoint->data[k + comPoint->size[0] * i3] = dv1[i3];
      }
    } else {
      /* If there is more than one edge */
      i3 = points->size[0] * points->size[1];
      points->size[0] = edgeIdx->size[1];
      points->size[1] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)points, i3, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      loop_ub = edgeIdx->size[1] << 1;
      for (i3 = 0; i3 < loop_ub; i3++) {
        points->data[i3] = 0.0;
      }

      c_ii = 1;
      while (c_ii - 1 <= edgeIdx->size[1] - 1) {
        i3 = edgeIdx->size[1];
        if (!((c_ii >= 1) && (c_ii <= i3))) {
          emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &qb_emlrtBCI, sp);
        }

        if (edgelabel->data[c_ii - 1] == 1.0) {
          /* For hinge */
          i3 = edgeIdx->size[1];
          i4 = (c_ii - 1) + 1;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &bb_emlrtBCI, sp);
          }

          i3 = DNA_edgelabel->size[1];
          if (!(1 <= i3)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i3, &ab_emlrtBCI, sp);
          }

          i3 = DNA_edgelabel->size[1];
          i4 = (int32_T)edgeIdx->data[c_ii - 1];
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &ab_emlrtBCI, sp);
          }

          loop_ub = (int32_T)edgeIdx->data[c_ii - 1];
          i3 = edgeIdx->size[1];
          if (!((c_ii >= 1) && (c_ii <= i3))) {
            emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &yb_emlrtBCI, sp);
          }

          b_edgelabel = edgelabel->data[c_ii - 1];
          i3 = e_DNA_edgelabel->size[0] * e_DNA_edgelabel->size[1];
          e_DNA_edgelabel->size[0] = 1;
          e_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity(sp, (emxArray__common *)e_DNA_edgelabel, i3,
                            (int32_T)sizeof(boolean_T), &d_emlrtRTEI);
          for (i3 = 0; i3 < loop_ub; i3++) {
            e_DNA_edgelabel->data[e_DNA_edgelabel->size[0] * i3] =
              (DNA_edgelabel->data[i3] == b_edgelabel);
          }

          st.site = &i_emlrtRSI;
          Hidx = sum(&st, e_DNA_edgelabel);
          i3 = DNA_Hpar->size[1];
          nx = (int32_T)Hidx;
          if (!((nx >= 1) && (nx <= i3))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &y_emlrtBCI, sp);
          }

          idx = points->size[0];
          if (!((c_ii >= 1) && (c_ii <= idx))) {
            emlrtDynamicBoundsCheckR2012b(c_ii, 1, idx, &k_emlrtBCI, sp);
          }

          for (i3 = 0; i3 < 2; i3++) {
            points->data[(c_ii + points->size[0] * i3) - 1] = DNA_Hpar->data[i3
              + DNA_Hpar->size[0] * (nx - 1)];
          }
        } else {
          i3 = edgeIdx->size[1];
          if (!((c_ii >= 1) && (c_ii <= i3))) {
            emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &rb_emlrtBCI, sp);
          }

          if (edgelabel->data[c_ii - 1] == 2.0) {
            /* For spring */
            st.site = &h_emlrtRSI;
            loop_ub = inc->size[0];
            i3 = inc->size[1];
            i4 = edgeIdx->size[1];
            if (!((c_ii >= 1) && (c_ii <= i4))) {
              emlrtDynamicBoundsCheckR2012b(c_ii, 1, i4, &wb_emlrtBCI, &st);
            }

            nx = (int32_T)edgeIdx->data[c_ii - 1];
            if (!((nx >= 1) && (nx <= i3))) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &x_emlrtBCI, &st);
            }

            for (i3 = 0; i3 < loop_ub; i3++) {
              x_data[i3] = (inc->data[i3 + inc->size[0] * (nx - 1)] == 1.0);
            }

            b_st.site = &lb_emlrtRSI;
            idx = 0;
            c_st.site = &mb_emlrtRSI;
            nx = 1;
            exitg1 = false;
            while ((!exitg1) && (nx <= loop_ub)) {
              guard1 = false;
              if (x_data[nx - 1]) {
                idx++;
                ii_data[idx - 1] = nx;
                if (idx >= loop_ub) {
                  exitg1 = true;
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                nx++;
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
                i3 = 0;
              } else {
                i3 = idx;
              }

              iv0[0] = 1;
              iv0[1] = i3;
              c_st.site = &nb_emlrtRSI;
              indexShapeCheck(&c_st, loop_ub, iv0);
              loop_ub = i3;
            }

            for (i3 = 0; i3 < loop_ub; i3++) {
              i_data[i3] = ii_data[i3];
            }

            i3 = edgeIdx->size[1];
            i4 = (c_ii - 1) + 1;
            if (!((i4 >= 1) && (i4 <= i3))) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &w_emlrtBCI, sp);
            }

            i3 = DNA_edgelabel->size[1];
            if (!(1 <= i3)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i3, &v_emlrtBCI, sp);
            }

            i3 = DNA_edgelabel->size[1];
            i4 = (int32_T)edgeIdx->data[c_ii - 1];
            if (!((i4 >= 1) && (i4 <= i3))) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &v_emlrtBCI, sp);
            }

            b_loop_ub = (int32_T)edgeIdx->data[c_ii - 1];
            i3 = edgeIdx->size[1];
            if (!((c_ii >= 1) && (c_ii <= i3))) {
              emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &xb_emlrtBCI, sp);
            }

            b_edgelabel = edgelabel->data[c_ii - 1];
            i3 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
            d_DNA_edgelabel->size[0] = 1;
            d_DNA_edgelabel->size[1] = b_loop_ub;
            emxEnsureCapacity(sp, (emxArray__common *)d_DNA_edgelabel, i3,
                              (int32_T)sizeof(boolean_T), &d_emlrtRTEI);
            for (i3 = 0; i3 < b_loop_ub; i3++) {
              d_DNA_edgelabel->data[d_DNA_edgelabel->size[0] * i3] =
                (DNA_edgelabel->data[i3] == b_edgelabel);
            }

            st.site = &g_emlrtRSI;
            Sidx = sum(&st, d_DNA_edgelabel);
            if (!(1 <= loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &u_emlrtBCI, sp);
            }

            if (1.0 + (real_T)k == (real_T)i_data[0] - 1.0) {
              i3 = DNA_Spar->size[1];
              nx = (int32_T)Sidx;
              if (!((nx >= 1) && (nx <= i3))) {
                emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &t_emlrtBCI, sp);
              }

              idx = points->size[0];
              if (!((c_ii >= 1) && (c_ii <= idx))) {
                emlrtDynamicBoundsCheckR2012b(c_ii, 1, idx, &j_emlrtBCI, sp);
              }

              for (i3 = 0; i3 < 2; i3++) {
                points->data[(c_ii + points->size[0] * i3) - 1] = DNA_Spar->
                  data[i3 + DNA_Spar->size[0] * (nx - 1)];
              }
            } else {
              if (!(2 <= loop_ub)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, loop_ub, &s_emlrtBCI, sp);
              }

              if (1.0 + (real_T)k == (real_T)i_data[1] - 1.0) {
                i3 = DNA_Spar->size[1];
                nx = (int32_T)Sidx;
                if (!((nx >= 1) && (nx <= i3))) {
                  emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &r_emlrtBCI, sp);
                }

                idx = points->size[0];
                if (!((c_ii >= 1) && (c_ii <= idx))) {
                  emlrtDynamicBoundsCheckR2012b(c_ii, 1, idx, &i_emlrtBCI, sp);
                }

                for (i3 = 0; i3 < 2; i3++) {
                  points->data[(c_ii + points->size[0] * i3) - 1] =
                    DNA_Spar->data[(i3 + DNA_Spar->size[0] * (nx - 1)) + 2];
                }
              }
            }
          } else {
            i3 = edgeIdx->size[1];
            if (!((c_ii >= 1) && (c_ii <= i3))) {
              emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &sb_emlrtBCI, sp);
            }

            if (edgelabel->data[c_ii - 1] == 3.0) {
              /* For prismatic joint */
              i3 = edgeIdx->size[1];
              i4 = (c_ii - 1) + 1;
              if (!((i4 >= 1) && (i4 <= i3))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &q_emlrtBCI, sp);
              }

              i3 = DNA_edgelabel->size[1];
              if (!(1 <= i3)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i3, &p_emlrtBCI, sp);
              }

              i3 = DNA_edgelabel->size[1];
              i4 = (int32_T)edgeIdx->data[c_ii - 1];
              if (!((i4 >= 1) && (i4 <= i3))) {
                emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &p_emlrtBCI, sp);
              }

              loop_ub = (int32_T)edgeIdx->data[c_ii - 1];
              i3 = edgeIdx->size[1];
              if (!((c_ii >= 1) && (c_ii <= i3))) {
                emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &vb_emlrtBCI, sp);
              }

              b_edgelabel = edgelabel->data[c_ii - 1];
              i3 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
              c_DNA_edgelabel->size[0] = 1;
              c_DNA_edgelabel->size[1] = loop_ub;
              emxEnsureCapacity(sp, (emxArray__common *)c_DNA_edgelabel, i3,
                                (int32_T)sizeof(boolean_T), &d_emlrtRTEI);
              for (i3 = 0; i3 < loop_ub; i3++) {
                c_DNA_edgelabel->data[c_DNA_edgelabel->size[0] * i3] =
                  (DNA_edgelabel->data[i3] == b_edgelabel);
              }

              st.site = &f_emlrtRSI;
              Pidx = sum(&st, c_DNA_edgelabel);
              i3 = DNA_Ppar->size[1];
              nx = (int32_T)Pidx;
              if (!((nx >= 1) && (nx <= i3))) {
                emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &o_emlrtBCI, sp);
              }

              idx = points->size[0];
              if (!((c_ii >= 1) && (c_ii <= idx))) {
                emlrtDynamicBoundsCheckR2012b(c_ii, 1, idx, &h_emlrtBCI, sp);
              }

              for (i3 = 0; i3 < 2; i3++) {
                points->data[(c_ii + points->size[0] * i3) - 1] = DNA_Ppar->
                  data[i3 + DNA_Ppar->size[0] * (nx - 1)];
              }
            } else {
              i3 = edgeIdx->size[1];
              if (!((c_ii >= 1) && (c_ii <= i3))) {
                emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &tb_emlrtBCI, sp);
              }

              if (edgelabel->data[c_ii - 1] == 4.0) {
                i3 = edgeIdx->size[1];
                i4 = (c_ii - 1) + 1;
                if (!((i4 >= 1) && (i4 <= i3))) {
                  emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &n_emlrtBCI, sp);
                }

                i3 = DNA_edgelabel->size[1];
                if (!(1 <= i3)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i3, &m_emlrtBCI, sp);
                }

                i3 = DNA_edgelabel->size[1];
                i4 = (int32_T)edgeIdx->data[c_ii - 1];
                if (!((i4 >= 1) && (i4 <= i3))) {
                  emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &m_emlrtBCI, sp);
                }

                loop_ub = (int32_T)edgeIdx->data[c_ii - 1];
                i3 = edgeIdx->size[1];
                if (!((c_ii >= 1) && (c_ii <= i3))) {
                  emlrtDynamicBoundsCheckR2012b(c_ii, 1, i3, &ub_emlrtBCI, sp);
                }

                b_edgelabel = edgelabel->data[c_ii - 1];
                i3 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
                b_DNA_edgelabel->size[0] = 1;
                b_DNA_edgelabel->size[1] = loop_ub;
                emxEnsureCapacity(sp, (emxArray__common *)b_DNA_edgelabel, i3,
                                  (int32_T)sizeof(boolean_T), &d_emlrtRTEI);
                for (i3 = 0; i3 < loop_ub; i3++) {
                  b_DNA_edgelabel->data[b_DNA_edgelabel->size[0] * i3] =
                    (DNA_edgelabel->data[i3] == b_edgelabel);
                }

                st.site = &e_emlrtRSI;
                Pmidx = sum(&st, b_DNA_edgelabel);
                i3 = DNA_Pmpar->size[1];
                nx = (int32_T)Pmidx;
                if (!((nx >= 1) && (nx <= i3))) {
                  emlrtDynamicBoundsCheckR2012b(nx, 1, i3, &l_emlrtBCI, sp);
                }

                idx = points->size[0];
                if (!((c_ii >= 1) && (c_ii <= idx))) {
                  emlrtDynamicBoundsCheckR2012b(c_ii, 1, idx, &g_emlrtBCI, sp);
                }

                for (i3 = 0; i3 < 2; i3++) {
                  points->data[(c_ii + points->size[0] * i3) - 1] =
                    DNA_Pmpar->data[i3 + DNA_Pmpar->size[0] * (nx - 1)];
                }
              }
            }
          }
        }

        c_ii++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      st.site = &d_emlrtRSI;
      b_mean(&st, points, dv1);
      nx = comPoint->size[0];
      i3 = 1 + k;
      if (!((i3 >= 1) && (i3 <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, nx, &e_emlrtBCI, sp);
      }

      for (i3 = 0; i3 < 2; i3++) {
        comPoint->data[k + comPoint->size[0] * i3] = dv1[i3];
      }
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&i_DNA_edgelabel);
  emxFree_boolean_T(&h_DNA_edgelabel);
  emxFree_boolean_T(&g_DNA_edgelabel);
  emxFree_boolean_T(&f_DNA_edgelabel);
  emxFree_boolean_T(&e_DNA_edgelabel);
  emxFree_boolean_T(&d_DNA_edgelabel);
  emxFree_boolean_T(&c_DNA_edgelabel);
  emxFree_boolean_T(&b_DNA_edgelabel);
  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&vrtxIdx);
  emxFree_real_T(&points);
  emxFree_real_T(&edgelabel);
  emxFree_real_T(&edgeIdx);
  emxFree_real_T(&inc);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (getCompoints.c) */
