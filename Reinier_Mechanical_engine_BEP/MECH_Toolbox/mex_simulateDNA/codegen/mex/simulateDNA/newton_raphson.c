/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * newton_raphson.c
 *
 * Code generation for function 'newton_raphson'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "newton_raphson.h"
#include "simulateDNA_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "mrdivide.h"
#include "getDk.h"
#include "abs.h"
#include "indexShapeCheck.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 6, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo kc_emlrtRSI = { 7, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo lc_emlrtRSI = { 12, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo mc_emlrtRSI = { 15, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo nc_emlrtRSI = { 19, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo oc_emlrtRSI = { 22, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo pc_emlrtRSI = { 24, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo qc_emlrtRSI = { 35, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo rc_emlrtRSI = { 36, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo sc_emlrtRSI = { 41, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo tc_emlrtRSI = { 44, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo uc_emlrtRSI = { 45, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo vc_emlrtRSI = { 47, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo wc_emlrtRSI = { 49, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRSInfo ae_emlrtRSI = { 68, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRSInfo be_emlrtRSI = { 21, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRSInfo ce_emlrtRSI = { 85, "xgemm",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"
};

static emlrtRTEInfo ab_emlrtRTEI = { 1, 16, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo ec_emlrtRTEI = { 12, 1, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo fc_emlrtRTEI = { 22, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo gc_emlrtRTEI = { 24, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo hc_emlrtRTEI = { 36, 1, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo ic_emlrtRTEI = { 49, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 6, 11, "qss", "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 6, 11, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  1 };

static emlrtDCInfo r_emlrtDCI = { 7, 12, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  1 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 7, 12, "qss", "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  0 };

static emlrtECInfo s_emlrtECI = { -1, 24, 13, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 29, 5, "qss", "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 29, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  1 };

static emlrtECInfo t_emlrtECI = { -1, 29, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtECInfo u_emlrtECI = { -1, 36, 6, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtECInfo v_emlrtECI = { -1, 45, 12, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtECInfo w_emlrtECI = { -1, 49, 14, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtDCInfo t_emlrtDCI = { 54, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  1 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 54, 5, "qss", "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m",
  0 };

static emlrtECInfo x_emlrtECI = { -1, 54, 5, "newton_raphson",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\newton_raphson.m"
};

static emlrtRTEInfo jd_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRTEInfo kd_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

/* Function Definitions */
void newton_raphson(const emlrtStack *sp, real_T t, emxArray_real_T *qss, real_T
                    nx0, const emxArray_real_T *DNA_incstr, const
                    emxArray_real_T *DNA_edgelabel, const emxArray_real_T
                    *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
                    emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
                    const emxArray_real_T *DNA_Pmpar)
{
  int32_T i55;
  int32_T ixstart;
  emxArray_real_T *q_new;
  int32_T iv94[2];
  real_T mtmp;
  int32_T i56;
  emxArray_real_T *qd_new;
  int32_T iv95[2];
  int32_T i57;
  emxArray_real_T *D;
  int32_T iter;
  emxArray_real_T *invJ;
  emxArray_real_T *Dt;
  emxArray_int32_T *r18;
  emxArray_real_T *C;
  emxArray_real_T *varargin_1;
  emxArray_real_T *b;
  emxArray_real_T *b_invJ;
  int32_T exitg3;
  boolean_T overflow;
  int32_T n;
  int32_T ix;
  boolean_T exitg4;
  emxArray_real_T *Dd;
  uint32_T invJ_idx_0;
  uint32_T unnamed_idx_1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  emxArray_real_T *b_C;
  ptrdiff_t lda_t;
  emxArray_real_T *c_C;
  ptrdiff_t ldb_t;
  emxArray_real_T *d_C;
  ptrdiff_t ldc_t;
  emxArray_real_T *c_invJ;
  int32_T exitg1;
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (1.0 > nx0) {
    ixstart = 0;
  } else {
    i55 = qss->size[0];
    if (!(1 <= i55)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i55, &xh_emlrtBCI, sp);
    }

    if (nx0 != (int32_T)muDoubleScalarFloor(nx0)) {
      emlrtIntegerCheckR2012b(nx0, &q_emlrtDCI, sp);
    }

    i55 = qss->size[0];
    ixstart = (int32_T)nx0;
    if (!((ixstart >= 1) && (ixstart <= i55))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, i55, &xh_emlrtBCI, sp);
    }
  }

  emxInit_real_T1(sp, &q_new, 1, &gc_emlrtRTEI, true);
  iv94[0] = 1;
  iv94[1] = ixstart;
  st.site = &jc_emlrtRSI;
  indexShapeCheck(&st, qss->size[0], iv94);
  i55 = q_new->size[0];
  q_new->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)q_new, i55, (int32_T)sizeof(real_T),
                    &ab_emlrtRTEI);
  for (i55 = 0; i55 < ixstart; i55++) {
    q_new->data[i55] = qss->data[i55];
  }

  mtmp = nx0 * 2.0;
  if (nx0 + 1.0 > mtmp) {
    i56 = 1;
    i55 = 1;
  } else {
    if (nx0 + 1.0 != (int32_T)muDoubleScalarFloor(nx0 + 1.0)) {
      emlrtIntegerCheckR2012b(nx0 + 1.0, &r_emlrtDCI, sp);
    }

    i55 = qss->size[0];
    i56 = (int32_T)(nx0 + 1.0);
    if (!((i56 >= 1) && (i56 <= i55))) {
      emlrtDynamicBoundsCheckR2012b(i56, 1, i55, &yh_emlrtBCI, sp);
    }

    if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
      emlrtIntegerCheckR2012b(mtmp, &r_emlrtDCI, sp);
    }

    i55 = qss->size[0];
    i57 = (int32_T)mtmp;
    if (!((i57 >= 1) && (i57 <= i55))) {
      emlrtDynamicBoundsCheckR2012b(i57, 1, i55, &yh_emlrtBCI, sp);
    }

    i55 = i57 + 1;
  }

  emxInit_real_T1(sp, &qd_new, 1, &ic_emlrtRTEI, true);
  iv95[0] = 1;
  iv95[1] = i55 - i56;
  st.site = &kc_emlrtRSI;
  indexShapeCheck(&st, qss->size[0], iv95);
  i57 = qd_new->size[0];
  qd_new->size[0] = i55 - i56;
  emxEnsureCapacity(sp, (emxArray__common *)qd_new, i57, (int32_T)sizeof(real_T),
                    &ab_emlrtRTEI);
  ixstart = i55 - i56;
  for (i55 = 0; i55 < ixstart; i55++) {
    qd_new->data[i55] = qss->data[(i56 + i55) - 1];
  }

  emxInit_real_T1(sp, &D, 1, &ec_emlrtRTEI, true);
  iter = 0;

  /*  F = constraint(q_tilde); */
  st.site = &lc_emlrtRSI;
  getDk(&st, t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
        DNA_Ppar, DNA_Pmpar, D);

  /* constraint vector */
  emxInit_real_T(sp, &invJ, 2, &fc_emlrtRTEI, true);
  emxInit_real_T1(sp, &Dt, 1, &ab_emlrtRTEI, true);
  emxInit_int32_T(sp, &r18, 2, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &C, 2, &ab_emlrtRTEI, true);
  emxInit_real_T1(sp, &varargin_1, 1, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &b_invJ, 2, &ab_emlrtRTEI, true);
  do {
    exitg3 = 0;
    st.site = &mc_emlrtRSI;
    b_abs(&st, D, varargin_1);
    st.site = &mc_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if ((varargin_1->size[0] == 1) || (varargin_1->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &mc_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (varargin_1->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &oc_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &ab_emlrtRSI;
    ixstart = 1;
    n = varargin_1->size[0];
    mtmp = varargin_1->data[0];
    if (varargin_1->size[0] > 1) {
      if (muDoubleScalarIsNaN(varargin_1->data[0])) {
        e_st.site = &cb_emlrtRSI;
        overflow = (varargin_1->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = 2;
        exitg4 = false;
        while ((!exitg4) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(varargin_1->data[ix - 1])) {
            mtmp = varargin_1->data[ix - 1];
            exitg4 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < varargin_1->size[0]) {
        e_st.site = &bb_emlrtRSI;
        overflow = ((!(ixstart + 1 > varargin_1->size[0])) && (varargin_1->size
          [0] > 2147483646));
        if (overflow) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= n) {
          if (varargin_1->data[ixstart] > mtmp) {
            mtmp = varargin_1->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if ((mtmp > 1.0E-12) && (iter < 1000)) {
      /*      J = constraintd(q_tilde); */
      /*      F = constraint(q_tilde); */
      st.site = &nc_emlrtRSI;
      b_getDk(&st, t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
              DNA_Spar, DNA_Ppar, DNA_Pmpar, D, invJ);

      /*      F = getDk(qss,DNA); */
      st.site = &oc_emlrtRSI;
      i55 = b->size[0] * b->size[1];
      b->size[0] = invJ->size[1];
      b->size[1] = invJ->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)b, i55, (int32_T)sizeof(real_T),
                        &ab_emlrtRTEI);
      ixstart = invJ->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        n = invJ->size[1];
        for (i56 = 0; i56 < n; i56++) {
          b->data[i56 + b->size[0] * i55] = invJ->data[i55 + invJ->size[0] * i56];
        }
      }

      b_st.site = &be_emlrtRSI;
      if (!(invJ->size[1] == b->size[0])) {
        if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || ((b->size[0] == 1)
             && (b->size[1] == 1))) {
          emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((invJ->size[1] == 1) || (b->size[0] == 1)) {
        i55 = C->size[0] * C->size[1];
        C->size[0] = invJ->size[0];
        C->size[1] = b->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = invJ->size[0];
        for (i55 = 0; i55 < ixstart; i55++) {
          n = b->size[1];
          for (i56 = 0; i56 < n; i56++) {
            C->data[i55 + C->size[0] * i56] = 0.0;
            ix = invJ->size[1];
            for (i57 = 0; i57 < ix; i57++) {
              C->data[i55 + C->size[0] * i56] += invJ->data[i55 + invJ->size[0] *
                i57] * b->data[i57 + b->size[0] * i56];
            }
          }
        }
      } else {
        invJ_idx_0 = (uint32_T)invJ->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i55 = C->size[0] * C->size[1];
        C->size[0] = (int32_T)invJ_idx_0;
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = C->size[1];
        for (i55 = 0; i55 < ixstart; i55++) {
          n = C->size[0];
          for (i56 = 0; i56 < n; i56++) {
            C->data[i56 + C->size[0] * i55] = 0.0;
          }
        }

        b_st.site = &ae_emlrtRSI;
        if ((invJ->size[0] < 1) || (b->size[1] < 1) || (invJ->size[1] < 1)) {
        } else {
          c_st.site = &ce_emlrtRSI;
          mtmp = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)invJ->size[0];
          n_t = (ptrdiff_t)b->size[1];
          k_t = (ptrdiff_t)invJ->size[1];
          lda_t = (ptrdiff_t)invJ->size[0];
          ldb_t = (ptrdiff_t)invJ->size[1];
          ldc_t = (ptrdiff_t)invJ->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0],
                &lda_t, &b->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }
      }

      i55 = b_invJ->size[0] * b_invJ->size[1];
      b_invJ->size[0] = invJ->size[1];
      b_invJ->size[1] = invJ->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_invJ, i55, (int32_T)sizeof
                        (real_T), &ab_emlrtRTEI);
      ixstart = invJ->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        n = invJ->size[1];
        for (i56 = 0; i56 < n; i56++) {
          b_invJ->data[i56 + b_invJ->size[0] * i55] = invJ->data[i55 +
            invJ->size[0] * i56];
        }
      }

      st.site = &oc_emlrtRSI;
      mrdivide(&st, b_invJ, C, invJ);
      st.site = &pc_emlrtRSI;
      b_st.site = &be_emlrtRSI;
      if (!(invJ->size[1] == D->size[0])) {
        if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || (D->size[0] == 1))
        {
          emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((invJ->size[1] == 1) || (D->size[0] == 1)) {
        i55 = Dt->size[0];
        Dt->size[0] = invJ->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)Dt, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = invJ->size[0];
        for (i55 = 0; i55 < ixstart; i55++) {
          Dt->data[i55] = 0.0;
          n = invJ->size[1];
          for (i56 = 0; i56 < n; i56++) {
            Dt->data[i55] += invJ->data[i55 + invJ->size[0] * i56] * D->data[i56];
          }
        }
      } else {
        invJ_idx_0 = (uint32_T)invJ->size[0];
        i55 = Dt->size[0];
        Dt->size[0] = (int32_T)invJ_idx_0;
        emxEnsureCapacity(&st, (emxArray__common *)Dt, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = Dt->size[0];
        i55 = Dt->size[0];
        Dt->size[0] = ixstart;
        emxEnsureCapacity(&st, (emxArray__common *)Dt, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        for (i55 = 0; i55 < ixstart; i55++) {
          Dt->data[i55] = 0.0;
        }

        b_st.site = &ae_emlrtRSI;
        if ((invJ->size[0] < 1) || (invJ->size[1] < 1)) {
        } else {
          c_st.site = &ce_emlrtRSI;
          mtmp = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)invJ->size[0];
          n_t = (ptrdiff_t)1;
          k_t = (ptrdiff_t)invJ->size[1];
          lda_t = (ptrdiff_t)invJ->size[0];
          ldb_t = (ptrdiff_t)invJ->size[1];
          ldc_t = (ptrdiff_t)invJ->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0],
                &lda_t, &D->data[0], &ldb_t, &beta1, &Dt->data[0], &ldc_t);
        }
      }

      i55 = q_new->size[0];
      i56 = Dt->size[0];
      if (i55 != i56) {
        emlrtSizeEqCheck1DR2012b(i55, i56, &s_emlrtECI, sp);
      }

      i55 = q_new->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)q_new, i55, (int32_T)sizeof
                        (real_T), &ab_emlrtRTEI);
      ixstart = q_new->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        q_new->data[i55] -= Dt->data[i55];
      }

      iter++;
      if (1.0 > nx0) {
        ixstart = 0;
      } else {
        i55 = qss->size[0];
        if (!(1 <= i55)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i55, &ai_emlrtBCI, sp);
        }

        if (nx0 != (int32_T)muDoubleScalarFloor(nx0)) {
          emlrtIntegerCheckR2012b(nx0, &s_emlrtDCI, sp);
        }

        i55 = qss->size[0];
        ixstart = (int32_T)nx0;
        if (!((ixstart >= 1) && (ixstart <= i55))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, i55, &ai_emlrtBCI, sp);
        }
      }

      i55 = q_new->size[0];
      if (ixstart != i55) {
        emlrtSizeEqCheck1DR2012b(ixstart, i55, &t_emlrtECI, sp);
      }

      i55 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = ixstart;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i55, (int32_T)sizeof
                        (int32_T), &ab_emlrtRTEI);
      for (i55 = 0; i55 < ixstart; i55++) {
        r18->data[r18->size[0] * i55] = i55;
      }

      ixstart = r18->size[1];
      for (i55 = 0; i55 < ixstart; i55++) {
        qss->data[r18->data[r18->size[0] * i55]] = q_new->data[(*(int32_T (*)[2])
          r18->size)[0] * i55];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  emxFree_real_T(&b_invJ);
  emxFree_real_T(&C);
  emxFree_real_T(&q_new);

  /*  F = constraintd(qss)*qd_tilde; */
  st.site = &qc_emlrtRSI;
  c_getDk(&st, t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
          DNA_Ppar, DNA_Pmpar, D, invJ, varargin_1, Dt);
  st.site = &rc_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  if (!(invJ->size[1] == qd_new->size[0])) {
    if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || (qd_new->size[0] == 1))
    {
      emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
        "Coder:MATLAB:innerdim", 0);
    }
  }

  emxInit_real_T1(&st, &Dd, 1, &hc_emlrtRTEI, true);
  if ((invJ->size[1] == 1) || (qd_new->size[0] == 1)) {
    i55 = Dd->size[0];
    Dd->size[0] = invJ->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)Dd, i55, (int32_T)sizeof(real_T),
                      &ab_emlrtRTEI);
    ixstart = invJ->size[0];
    for (i55 = 0; i55 < ixstart; i55++) {
      Dd->data[i55] = 0.0;
      n = invJ->size[1];
      for (i56 = 0; i56 < n; i56++) {
        Dd->data[i55] += invJ->data[i55 + invJ->size[0] * i56] * qd_new->
          data[i56];
      }
    }
  } else {
    invJ_idx_0 = (uint32_T)invJ->size[0];
    i55 = Dd->size[0];
    Dd->size[0] = (int32_T)invJ_idx_0;
    emxEnsureCapacity(&st, (emxArray__common *)Dd, i55, (int32_T)sizeof(real_T),
                      &ab_emlrtRTEI);
    ixstart = Dd->size[0];
    i55 = Dd->size[0];
    Dd->size[0] = ixstart;
    emxEnsureCapacity(&st, (emxArray__common *)Dd, i55, (int32_T)sizeof(real_T),
                      &ab_emlrtRTEI);
    for (i55 = 0; i55 < ixstart; i55++) {
      Dd->data[i55] = 0.0;
    }

    b_st.site = &ae_emlrtRSI;
    if ((invJ->size[0] < 1) || (invJ->size[1] < 1)) {
    } else {
      c_st.site = &ce_emlrtRSI;
      mtmp = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)invJ->size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)invJ->size[1];
      lda_t = (ptrdiff_t)invJ->size[0];
      ldb_t = (ptrdiff_t)invJ->size[1];
      ldc_t = (ptrdiff_t)invJ->size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0], &lda_t,
            &qd_new->data[0], &ldb_t, &beta1, &Dd->data[0], &ldc_t);
    }
  }

  i55 = Dd->size[0];
  i56 = Dt->size[0];
  if (i55 != i56) {
    emlrtSizeEqCheck1DR2012b(i55, i56, &u_emlrtECI, sp);
  }

  i55 = Dd->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Dd, i55, (int32_T)sizeof(real_T),
                    &ab_emlrtRTEI);
  ixstart = Dd->size[0];
  for (i55 = 0; i55 < ixstart; i55++) {
    Dd->data[i55] += Dt->data[i55];
  }

  emxFree_real_T(&Dt);
  iter = 0;
  emxInit_real_T1(sp, &b_C, 1, &ab_emlrtRTEI, true);
  emxInit_real_T1(sp, &c_C, 1, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &d_C, 2, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &c_invJ, 2, &ab_emlrtRTEI, true);
  do {
    exitg1 = 0;
    st.site = &sc_emlrtRSI;
    b_abs(&st, Dd, varargin_1);
    st.site = &sc_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if ((varargin_1->size[0] == 1) || (varargin_1->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &mc_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (varargin_1->size[0] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &oc_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &ab_emlrtRSI;
    ixstart = 1;
    n = varargin_1->size[0];
    mtmp = varargin_1->data[0];
    if (varargin_1->size[0] > 1) {
      if (muDoubleScalarIsNaN(varargin_1->data[0])) {
        e_st.site = &cb_emlrtRSI;
        overflow = (varargin_1->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = 2;
        exitg2 = false;
        while ((!exitg2) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(varargin_1->data[ix - 1])) {
            mtmp = varargin_1->data[ix - 1];
            exitg2 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < varargin_1->size[0]) {
        e_st.site = &bb_emlrtRSI;
        overflow = ((!(ixstart + 1 > varargin_1->size[0])) && (varargin_1->size
          [0] > 2147483646));
        if (overflow) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= n) {
          if (varargin_1->data[ixstart] > mtmp) {
            mtmp = varargin_1->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if ((mtmp > 1.0E-12) && (iter < 1000)) {
      /*      J   = constraintd(qss(1:nx0)); */
      st.site = &tc_emlrtRSI;
      c_getDk(&st, t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
              DNA_Spar, DNA_Ppar, DNA_Pmpar, D, invJ, varargin_1, Dd);
      st.site = &uc_emlrtRSI;
      b_st.site = &be_emlrtRSI;
      if (!(invJ->size[1] == qd_new->size[0])) {
        if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || (qd_new->size[0] ==
             1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((invJ->size[1] == 1) || (qd_new->size[0] == 1)) {
        i55 = b_C->size[0];
        b_C->size[0] = invJ->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)b_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = invJ->size[0];
        for (i55 = 0; i55 < ixstart; i55++) {
          b_C->data[i55] = 0.0;
          n = invJ->size[1];
          for (i56 = 0; i56 < n; i56++) {
            b_C->data[i55] += invJ->data[i55 + invJ->size[0] * i56] *
              qd_new->data[i56];
          }
        }
      } else {
        invJ_idx_0 = (uint32_T)invJ->size[0];
        i55 = b_C->size[0];
        b_C->size[0] = (int32_T)invJ_idx_0;
        emxEnsureCapacity(&st, (emxArray__common *)b_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = b_C->size[0];
        i55 = b_C->size[0];
        b_C->size[0] = ixstart;
        emxEnsureCapacity(&st, (emxArray__common *)b_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        for (i55 = 0; i55 < ixstart; i55++) {
          b_C->data[i55] = 0.0;
        }

        b_st.site = &ae_emlrtRSI;
        if ((invJ->size[0] < 1) || (invJ->size[1] < 1)) {
        } else {
          c_st.site = &ce_emlrtRSI;
          mtmp = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)invJ->size[0];
          n_t = (ptrdiff_t)1;
          k_t = (ptrdiff_t)invJ->size[1];
          lda_t = (ptrdiff_t)invJ->size[0];
          ldb_t = (ptrdiff_t)invJ->size[1];
          ldc_t = (ptrdiff_t)invJ->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0],
                &lda_t, &qd_new->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }
      }

      i55 = b_C->size[0];
      i56 = Dd->size[0];
      if (i55 != i56) {
        emlrtSizeEqCheck1DR2012b(i55, i56, &v_emlrtECI, sp);
      }

      i55 = Dd->size[0];
      Dd->size[0] = b_C->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)Dd, i55, (int32_T)sizeof(real_T),
                        &ab_emlrtRTEI);
      ixstart = b_C->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        Dd->data[i55] += b_C->data[i55];
      }

      st.site = &vc_emlrtRSI;
      i55 = b->size[0] * b->size[1];
      b->size[0] = invJ->size[1];
      b->size[1] = invJ->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)b, i55, (int32_T)sizeof(real_T),
                        &ab_emlrtRTEI);
      ixstart = invJ->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        n = invJ->size[1];
        for (i56 = 0; i56 < n; i56++) {
          b->data[i56 + b->size[0] * i55] = invJ->data[i55 + invJ->size[0] * i56];
        }
      }

      b_st.site = &be_emlrtRSI;
      if (!(invJ->size[1] == b->size[0])) {
        if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || ((b->size[0] == 1)
             && (b->size[1] == 1))) {
          emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((invJ->size[1] == 1) || (b->size[0] == 1)) {
        i55 = d_C->size[0] * d_C->size[1];
        d_C->size[0] = invJ->size[0];
        d_C->size[1] = b->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)d_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = invJ->size[0];
        for (i55 = 0; i55 < ixstart; i55++) {
          n = b->size[1];
          for (i56 = 0; i56 < n; i56++) {
            d_C->data[i55 + d_C->size[0] * i56] = 0.0;
            ix = invJ->size[1];
            for (i57 = 0; i57 < ix; i57++) {
              d_C->data[i55 + d_C->size[0] * i56] += invJ->data[i55 + invJ->
                size[0] * i57] * b->data[i57 + b->size[0] * i56];
            }
          }
        }
      } else {
        invJ_idx_0 = (uint32_T)invJ->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i55 = d_C->size[0] * d_C->size[1];
        d_C->size[0] = (int32_T)invJ_idx_0;
        d_C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)d_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = d_C->size[1];
        for (i55 = 0; i55 < ixstart; i55++) {
          n = d_C->size[0];
          for (i56 = 0; i56 < n; i56++) {
            d_C->data[i56 + d_C->size[0] * i55] = 0.0;
          }
        }

        b_st.site = &ae_emlrtRSI;
        if ((invJ->size[0] < 1) || (b->size[1] < 1) || (invJ->size[1] < 1)) {
        } else {
          c_st.site = &ce_emlrtRSI;
          mtmp = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)invJ->size[0];
          n_t = (ptrdiff_t)b->size[1];
          k_t = (ptrdiff_t)invJ->size[1];
          lda_t = (ptrdiff_t)invJ->size[0];
          ldb_t = (ptrdiff_t)invJ->size[1];
          ldc_t = (ptrdiff_t)invJ->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0],
                &lda_t, &b->data[0], &ldb_t, &beta1, &d_C->data[0], &ldc_t);
        }
      }

      i55 = c_invJ->size[0] * c_invJ->size[1];
      c_invJ->size[0] = invJ->size[1];
      c_invJ->size[1] = invJ->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)c_invJ, i55, (int32_T)sizeof
                        (real_T), &ab_emlrtRTEI);
      ixstart = invJ->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        n = invJ->size[1];
        for (i56 = 0; i56 < n; i56++) {
          c_invJ->data[i56 + c_invJ->size[0] * i55] = invJ->data[i55 +
            invJ->size[0] * i56];
        }
      }

      st.site = &vc_emlrtRSI;
      mrdivide(&st, c_invJ, d_C, invJ);
      st.site = &wc_emlrtRSI;
      b_st.site = &be_emlrtRSI;
      if (!(invJ->size[1] == Dd->size[0])) {
        if (((invJ->size[0] == 1) && (invJ->size[1] == 1)) || (Dd->size[0] == 1))
        {
          emlrtErrorWithMessageIdR2012b(&b_st, &kd_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((invJ->size[1] == 1) || (Dd->size[0] == 1)) {
        i55 = c_C->size[0];
        c_C->size[0] = invJ->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)c_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = invJ->size[0];
        for (i55 = 0; i55 < ixstart; i55++) {
          c_C->data[i55] = 0.0;
          n = invJ->size[1];
          for (i56 = 0; i56 < n; i56++) {
            c_C->data[i55] += invJ->data[i55 + invJ->size[0] * i56] * Dd->
              data[i56];
          }
        }
      } else {
        invJ_idx_0 = (uint32_T)invJ->size[0];
        i55 = c_C->size[0];
        c_C->size[0] = (int32_T)invJ_idx_0;
        emxEnsureCapacity(&st, (emxArray__common *)c_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        ixstart = c_C->size[0];
        i55 = c_C->size[0];
        c_C->size[0] = ixstart;
        emxEnsureCapacity(&st, (emxArray__common *)c_C, i55, (int32_T)sizeof
                          (real_T), &ab_emlrtRTEI);
        for (i55 = 0; i55 < ixstart; i55++) {
          c_C->data[i55] = 0.0;
        }

        b_st.site = &ae_emlrtRSI;
        if ((invJ->size[0] < 1) || (invJ->size[1] < 1)) {
        } else {
          c_st.site = &ce_emlrtRSI;
          mtmp = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)invJ->size[0];
          n_t = (ptrdiff_t)1;
          k_t = (ptrdiff_t)invJ->size[1];
          lda_t = (ptrdiff_t)invJ->size[0];
          ldb_t = (ptrdiff_t)invJ->size[1];
          ldc_t = (ptrdiff_t)invJ->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &invJ->data[0],
                &lda_t, &Dd->data[0], &ldb_t, &beta1, &c_C->data[0], &ldc_t);
        }
      }

      i55 = qd_new->size[0];
      i56 = c_C->size[0];
      if (i55 != i56) {
        emlrtSizeEqCheck1DR2012b(i55, i56, &w_emlrtECI, sp);
      }

      i55 = qd_new->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)qd_new, i55, (int32_T)sizeof
                        (real_T), &ab_emlrtRTEI);
      ixstart = qd_new->size[0];
      for (i55 = 0; i55 < ixstart; i55++) {
        qd_new->data[i55] -= c_C->data[i55];
      }

      iter++;
      mtmp = nx0 * 2.0;
      if (nx0 + 1.0 > mtmp) {
        i56 = 1;
        i55 = 1;
      } else {
        if (nx0 + 1.0 != (int32_T)muDoubleScalarFloor(nx0 + 1.0)) {
          emlrtIntegerCheckR2012b(nx0 + 1.0, &t_emlrtDCI, sp);
        }

        i55 = qss->size[0];
        i56 = (int32_T)(nx0 + 1.0);
        if (!((i56 >= 1) && (i56 <= i55))) {
          emlrtDynamicBoundsCheckR2012b(i56, 1, i55, &bi_emlrtBCI, sp);
        }

        if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
          emlrtIntegerCheckR2012b(mtmp, &t_emlrtDCI, sp);
        }

        i55 = qss->size[0];
        i57 = (int32_T)mtmp;
        if (!((i57 >= 1) && (i57 <= i55))) {
          emlrtDynamicBoundsCheckR2012b(i57, 1, i55, &bi_emlrtBCI, sp);
        }

        i55 = i57 + 1;
      }

      i57 = i55 - i56;
      ixstart = qd_new->size[0];
      if (i57 != ixstart) {
        emlrtSizeEqCheck1DR2012b(i57, ixstart, &x_emlrtECI, sp);
      }

      i57 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = i55 - i56;
      emxEnsureCapacity(sp, (emxArray__common *)r18, i57, (int32_T)sizeof
                        (int32_T), &ab_emlrtRTEI);
      ixstart = i55 - i56;
      for (i55 = 0; i55 < ixstart; i55++) {
        r18->data[r18->size[0] * i55] = (i56 + i55) - 1;
      }

      ixstart = r18->size[1];
      for (i55 = 0; i55 < ixstart; i55++) {
        qss->data[r18->data[r18->size[0] * i55]] = qd_new->data[(*(int32_T (*)[2])
          r18->size)[0] * i55];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&c_invJ);
  emxFree_real_T(&b);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&d_C);
  emxFree_int32_T(&r18);
  emxFree_real_T(&c_C);
  emxFree_real_T(&b_C);
  emxFree_real_T(&qd_new);
  emxFree_real_T(&Dd);
  emxFree_real_T(&invJ);
  emxFree_real_T(&D);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (newton_raphson.c) */
