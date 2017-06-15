/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DNA2inc.c
 *
 * Code generation for function 'DNA2inc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "DNA2inc.h"
#include "simulateDNA_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "str2inc.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 33, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo r_emlrtRSI = { 37, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo s_emlrtRSI = { 71, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo t_emlrtRSI = { 43, "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m"
};

static emlrtRSInfo u_emlrtRSI = { 53, "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m"
};

static emlrtRSInfo pb_emlrtRSI = { 210, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo qb_emlrtRSI = { 214, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo qd_emlrtRSI = { 55, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo rd_emlrtRSI = { 41, "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m"
};

static emlrtRSInfo sd_emlrtRSI = { 63, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo td_emlrtRSI = { 67, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRSInfo xg_emlrtRSI = { 59, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 31, 16, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 33, 1, "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m"
};

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 40, 24, "edgelist", "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 40, 27, "inc", "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 53, 32, "inc", "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 53, 16, "edgelist", "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 53, 5, "DNA2edgelist",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2edgelist.m"
};

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 40, 13, "inc", "DNA2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\DNA2inc.m",
  0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 7, 18, "DNA.incstr", "selectInctype",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\selectInctype.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 11, 18, "DNA.incstr", "selectInctype",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\selectInctype.m",
  0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 13, 18, "DNA.incstr", "selectInctype",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\selectInctype.m",
  0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 9, 18, "DNA.incstr", "selectInctype",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\selectInctype.m",
  0 };

/* Function Definitions */
void DNA2inc(const emlrtStack *sp, const emxArray_real_T *DNA_incstr,
             emxArray_real_T *inc)
{
  boolean_T overflow;
  emxArray_real_T *edgelist;
  int32_T ix;
  int32_T mtmp;
  int32_T k;
  uint32_T sedgelist[2];
  int32_T n;
  emxArray_real_T *varargin_1;
  boolean_T x_data[100];
  int32_T ii_data[100];
  int32_T b_ix;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv2[2];
  int32_T tmp_size[1];
  int32_T tmp_data[100];
  int32_T iv3[1];
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
  overflow = false;

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  st.site = &q_emlrtRSI;

  /* Function */
  b_st.site = &s_emlrtRSI;

  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Switch */
  emxInit_real_T(&b_st, &edgelist, 2, &m_emlrtRTEI, true);
  if (!(DNA_incstr->size[1] == 0)) {
    c_st.site = &t_emlrtRSI;
    str2inc(&c_st, DNA_incstr, inc);
    ix = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = DNA_incstr->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, ix, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    mtmp = DNA_incstr->size[1] << 1;
    for (ix = 0; ix < mtmp; ix++) {
      edgelist->data[ix] = 0.0;
    }

    k = 0;
    while (k <= inc->size[1] - 1) {
      ix = edgelist->size[1];
      n = k + 1;
      if (!((n >= 1) && (n <= ix))) {
        emlrtDynamicBoundsCheckR2012b(n, 1, ix, &ec_emlrtBCI, &b_st);
      }

      c_st.site = &u_emlrtRSI;
      mtmp = inc->size[0];
      ix = inc->size[1];
      n = 1 + k;
      if (!((n >= 1) && (n <= ix))) {
        emlrtDynamicBoundsCheckR2012b(n, 1, ix, &dc_emlrtBCI, &c_st);
      }

      for (ix = 0; ix < mtmp; ix++) {
        x_data[ix] = (inc->data[ix + inc->size[0] * (n - 1)] == 1.0);
      }

      d_st.site = &lb_emlrtRSI;
      n = 0;
      e_st.site = &mb_emlrtRSI;
      b_ix = 1;
      exitg1 = false;
      while ((!exitg1) && (b_ix <= mtmp)) {
        guard1 = false;
        if (x_data[b_ix - 1]) {
          n++;
          ii_data[n - 1] = b_ix;
          if (n >= mtmp) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          b_ix++;
        }
      }

      if (n <= mtmp) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &lc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (mtmp == 1) {
        if (n == 0) {
          mtmp = 0;
        }
      } else {
        if (1 > n) {
          ix = 0;
        } else {
          ix = n;
        }

        iv2[0] = 1;
        iv2[1] = ix;
        e_st.site = &nb_emlrtRSI;
        indexShapeCheck(&e_st, mtmp, iv2);
        mtmp = ix;
      }

      tmp_size[0] = mtmp;
      for (ix = 0; ix < mtmp; ix++) {
        tmp_data[ix] = ii_data[ix];
      }

      if (!overflow) {
        iv3[0] = 2;
        overflow = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv3, 1, tmp_size, 1, &emlrtECI, &b_st);
      for (ix = 0; ix < 2; ix++) {
        edgelist->data[ix + edgelist->size[0] * k] = tmp_data[ix];
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    ix = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, ix, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
  }

  /* Functioin */
  /* Function */
  for (ix = 0; ix < 2; ix++) {
    sedgelist[ix] = (uint32_T)edgelist->size[ix];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(sp, &varargin_1, 2, &l_emlrtRTEI, true);
    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    ix = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = edgelist->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, ix, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    d_st.site = &pb_emlrtRSI;
    overflow = (edgelist->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (n = 0; n + 1 <= edgelist->size[1]; n++) {
      ix = (n << 1) + 2;
      d_st.site = &qb_emlrtRSI;
      b_ix = (n << 1) + 1;
      mtmp = (int32_T)edgelist->data[ix - 2];
      if (b_ix < ix) {
        e_st.site = &bb_emlrtRSI;
        if ((!(b_ix + 1 > ix)) && (ix > 2147483646)) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (b_ix + 1 <= ix) {
          if ((int32_T)edgelist->data[b_ix] > mtmp) {
            mtmp = (int32_T)edgelist->data[b_ix];
          }

          b_ix++;
        }
      }

      varargin_1->data[n] = mtmp;
    }

    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    n = varargin_1->size[1];
    mtmp = (int32_T)varargin_1->data[0];
    if (varargin_1->size[1] > 1) {
      e_st.site = &bb_emlrtRSI;
      overflow = (varargin_1->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)varargin_1->data[ix] > mtmp) {
          mtmp = (int32_T)varargin_1->data[ix];
        }
      }
    }

    emxFree_real_T(&varargin_1);
    ix = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int32_T)sedgelist[1];
    emxEnsureCapacity(sp, (emxArray__common *)inc, ix, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
    mtmp *= (int32_T)sedgelist[1];
    for (ix = 0; ix < mtmp; ix++) {
      inc->data[ix] = 0.0;
    }

    k = 1;
    while (k - 1 <= (int32_T)sedgelist[1] - 1) {
      ix = edgelist->size[1];
      if (!((k >= 1) && (k <= ix))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, ix, &bc_emlrtBCI, sp);
      }

      b_ix = inc->size[0];
      n = inc->size[1];
      if (!((k >= 1) && (k <= n))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, n, &cc_emlrtBCI, sp);
      }

      for (ix = 0; ix < 2; ix++) {
        n = (int32_T)edgelist->data[ix + edgelist->size[0] * (k - 1)];
        if (!((n >= 1) && (n <= b_ix))) {
          emlrtDynamicBoundsCheckR2012b(n, 1, b_ix, &fc_emlrtBCI, sp);
        }

        inc->data[(n + inc->size[0] * (k - 1)) - 1] = 1.0;
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* For */
  } else {
    ix = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)inc, ix, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  }

  emxFree_real_T(&edgelist);

  /* If */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_DNA2inc(const emlrtStack *sp, const emxArray_real_T *DNA_incstr, const
               emxArray_real_T *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r7;
  boolean_T overflow;
  int32_T i14;
  int32_T loop_ub;
  emxArray_int32_T *r8;
  int32_T ix;
  int32_T n;
  int32_T mtmp;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  uint32_T sedgelist[2];
  emxArray_real_T *varargin_1;
  int32_T k;
  boolean_T x_data[100];
  int32_T ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv19[2];
  int32_T tmp_size[1];
  int32_T tmp_data[100];
  int32_T iv20[1];
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
  emxInit_boolean_T(sp, &r7, 2, &l_emlrtRTEI, true);
  overflow = false;

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  st.site = &q_emlrtRSI;

  /* Function */
  b_st.site = &qd_emlrtRSI;

  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  c_st.site = &rd_emlrtRSI;
  i14 = r7->size[0] * r7->size[1];
  r7->size[0] = 1;
  r7->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r7, i14, (int32_T)sizeof
                    (boolean_T), &l_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i14 = 0; i14 < loop_ub; i14++) {
    r7->data[i14] = (DNA_edgelabel->data[i14] == 1.0);
  }

  emxInit_int32_T(&c_st, &r8, 2, &l_emlrtRTEI, true);
  ix = r7->size[1] - 1;
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r7->data[loop_ub]) {
      n++;
    }
  }

  i14 = r8->size[0] * r8->size[1];
  r8->size[0] = 1;
  r8->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)r8, i14, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r7->data[loop_ub]) {
      r8->data[n] = loop_ub + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r7);
  n = DNA_incstr->size[1];
  loop_ub = r8->size[0] * r8->size[1];
  for (i14 = 0; i14 < loop_ub; i14++) {
    mtmp = r8->data[i14];
    if (!((mtmp >= 1) && (mtmp <= n))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, n, &de_emlrtBCI, &c_st);
    }
  }

  /* Switch */
  emxInit_real_T(&b_st, &edgelist, 2, &m_emlrtRTEI, true);
  if (!(r8->size[1] == 0)) {
    emxInit_real_T(&b_st, &b_DNA_incstr, 2, &l_emlrtRTEI, true);
    i14 = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = r8->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_DNA_incstr, i14, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    loop_ub = r8->size[0] * r8->size[1];
    for (i14 = 0; i14 < loop_ub; i14++) {
      b_DNA_incstr->data[i14] = DNA_incstr->data[r8->data[i14] - 1];
    }

    c_st.site = &t_emlrtRSI;
    str2inc(&c_st, b_DNA_incstr, inc);
    n = r8->size[1];
    i14 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i14, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    loop_ub = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i14 = 0; i14 < loop_ub; i14++) {
      edgelist->data[i14] = 0.0;
    }

    k = 0;
    while (k <= inc->size[1] - 1) {
      i14 = edgelist->size[1];
      mtmp = k + 1;
      if (!((mtmp >= 1) && (mtmp <= i14))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i14, &ec_emlrtBCI, &b_st);
      }

      c_st.site = &u_emlrtRSI;
      loop_ub = inc->size[0];
      i14 = inc->size[1];
      mtmp = 1 + k;
      if (!((mtmp >= 1) && (mtmp <= i14))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i14, &dc_emlrtBCI, &c_st);
      }

      for (i14 = 0; i14 < loop_ub; i14++) {
        x_data[i14] = (inc->data[i14 + inc->size[0] * (mtmp - 1)] == 1.0);
      }

      d_st.site = &lb_emlrtRSI;
      n = 0;
      e_st.site = &mb_emlrtRSI;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= loop_ub) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (n <= loop_ub) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &lc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (loop_ub == 1) {
        if (n == 0) {
          loop_ub = 0;
        }
      } else {
        if (1 > n) {
          i14 = 0;
        } else {
          i14 = n;
        }

        iv19[0] = 1;
        iv19[1] = i14;
        e_st.site = &nb_emlrtRSI;
        indexShapeCheck(&e_st, loop_ub, iv19);
        loop_ub = i14;
      }

      tmp_size[0] = loop_ub;
      for (i14 = 0; i14 < loop_ub; i14++) {
        tmp_data[i14] = ii_data[i14];
      }

      if (!overflow) {
        iv20[0] = 2;
        overflow = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv20, 1, tmp_size, 1, &emlrtECI, &b_st);
      for (i14 = 0; i14 < 2; i14++) {
        edgelist->data[i14 + edgelist->size[0] * k] = tmp_data[i14];
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i14 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i14, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
  }

  emxFree_int32_T(&r8);

  /* Functioin */
  /* Function */
  for (i14 = 0; i14 < 2; i14++) {
    sedgelist[i14] = (uint32_T)edgelist->size[i14];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(sp, &varargin_1, 2, &l_emlrtRTEI, true);
    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    i14 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = edgelist->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i14, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    d_st.site = &pb_emlrtRSI;
    overflow = (edgelist->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (loop_ub = 0; loop_ub + 1 <= edgelist->size[1]; loop_ub++) {
      ix = (loop_ub << 1) + 2;
      d_st.site = &qb_emlrtRSI;
      n = (loop_ub << 1) + 1;
      mtmp = (int32_T)edgelist->data[ix - 2];
      if (n < ix) {
        e_st.site = &bb_emlrtRSI;
        if ((!(n + 1 > ix)) && (ix > 2147483646)) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (n + 1 <= ix) {
          if ((int32_T)edgelist->data[n] > mtmp) {
            mtmp = (int32_T)edgelist->data[n];
          }

          n++;
        }
      }

      varargin_1->data[loop_ub] = mtmp;
    }

    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    n = varargin_1->size[1];
    mtmp = (int32_T)varargin_1->data[0];
    if (varargin_1->size[1] > 1) {
      e_st.site = &bb_emlrtRSI;
      overflow = (varargin_1->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)varargin_1->data[ix] > mtmp) {
          mtmp = (int32_T)varargin_1->data[ix];
        }
      }
    }

    emxFree_real_T(&varargin_1);
    i14 = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int32_T)sedgelist[1];
    emxEnsureCapacity(sp, (emxArray__common *)inc, i14, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
    loop_ub = mtmp * (int32_T)sedgelist[1];
    for (i14 = 0; i14 < loop_ub; i14++) {
      inc->data[i14] = 0.0;
    }

    k = 1;
    while (k - 1 <= (int32_T)sedgelist[1] - 1) {
      i14 = edgelist->size[1];
      if (!((k >= 1) && (k <= i14))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i14, &bc_emlrtBCI, sp);
      }

      ix = inc->size[0];
      n = inc->size[1];
      if (!((k >= 1) && (k <= n))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, n, &cc_emlrtBCI, sp);
      }

      for (i14 = 0; i14 < 2; i14++) {
        mtmp = (int32_T)edgelist->data[i14 + edgelist->size[0] * (k - 1)];
        if (!((mtmp >= 1) && (mtmp <= ix))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, ix, &fc_emlrtBCI, sp);
        }

        inc->data[(mtmp + inc->size[0] * (k - 1)) - 1] = 1.0;
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* For */
  } else {
    i14 = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)inc, i14, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  }

  emxFree_real_T(&edgelist);

  /* If */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_DNA2inc(const emlrtStack *sp, const emxArray_real_T *DNA_incstr, const
               emxArray_real_T *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r9;
  boolean_T overflow;
  int32_T i15;
  int32_T loop_ub;
  emxArray_int32_T *r10;
  int32_T ix;
  int32_T n;
  int32_T mtmp;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  uint32_T sedgelist[2];
  emxArray_real_T *varargin_1;
  int32_T k;
  boolean_T x_data[100];
  int32_T ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv21[2];
  int32_T tmp_size[1];
  int32_T tmp_data[100];
  int32_T iv22[1];
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
  emxInit_boolean_T(sp, &r9, 2, &l_emlrtRTEI, true);
  overflow = false;

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  st.site = &q_emlrtRSI;

  /* Function */
  b_st.site = &sd_emlrtRSI;

  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  c_st.site = &rd_emlrtRSI;
  i15 = r9->size[0] * r9->size[1];
  r9->size[0] = 1;
  r9->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r9, i15, (int32_T)sizeof
                    (boolean_T), &l_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    r9->data[i15] = (DNA_edgelabel->data[i15] == 3.0);
  }

  emxInit_int32_T(&c_st, &r10, 2, &l_emlrtRTEI, true);
  ix = r9->size[1] - 1;
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r9->data[loop_ub]) {
      n++;
    }
  }

  i15 = r10->size[0] * r10->size[1];
  r10->size[0] = 1;
  r10->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)r10, i15, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r9->data[loop_ub]) {
      r10->data[n] = loop_ub + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r9);
  n = DNA_incstr->size[1];
  loop_ub = r10->size[0] * r10->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    mtmp = r10->data[i15];
    if (!((mtmp >= 1) && (mtmp <= n))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, n, &ee_emlrtBCI, &c_st);
    }
  }

  /* Switch */
  emxInit_real_T(&b_st, &edgelist, 2, &m_emlrtRTEI, true);
  if (!(r10->size[1] == 0)) {
    emxInit_real_T(&b_st, &b_DNA_incstr, 2, &l_emlrtRTEI, true);
    i15 = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = r10->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_DNA_incstr, i15, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    loop_ub = r10->size[0] * r10->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_DNA_incstr->data[i15] = DNA_incstr->data[r10->data[i15] - 1];
    }

    c_st.site = &t_emlrtRSI;
    str2inc(&c_st, b_DNA_incstr, inc);
    n = r10->size[1];
    i15 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i15, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    loop_ub = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i15 = 0; i15 < loop_ub; i15++) {
      edgelist->data[i15] = 0.0;
    }

    k = 0;
    while (k <= inc->size[1] - 1) {
      i15 = edgelist->size[1];
      mtmp = k + 1;
      if (!((mtmp >= 1) && (mtmp <= i15))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i15, &ec_emlrtBCI, &b_st);
      }

      c_st.site = &u_emlrtRSI;
      loop_ub = inc->size[0];
      i15 = inc->size[1];
      mtmp = 1 + k;
      if (!((mtmp >= 1) && (mtmp <= i15))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i15, &dc_emlrtBCI, &c_st);
      }

      for (i15 = 0; i15 < loop_ub; i15++) {
        x_data[i15] = (inc->data[i15 + inc->size[0] * (mtmp - 1)] == 1.0);
      }

      d_st.site = &lb_emlrtRSI;
      n = 0;
      e_st.site = &mb_emlrtRSI;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= loop_ub) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (n <= loop_ub) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &lc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (loop_ub == 1) {
        if (n == 0) {
          loop_ub = 0;
        }
      } else {
        if (1 > n) {
          i15 = 0;
        } else {
          i15 = n;
        }

        iv21[0] = 1;
        iv21[1] = i15;
        e_st.site = &nb_emlrtRSI;
        indexShapeCheck(&e_st, loop_ub, iv21);
        loop_ub = i15;
      }

      tmp_size[0] = loop_ub;
      for (i15 = 0; i15 < loop_ub; i15++) {
        tmp_data[i15] = ii_data[i15];
      }

      if (!overflow) {
        iv22[0] = 2;
        overflow = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv22, 1, tmp_size, 1, &emlrtECI, &b_st);
      for (i15 = 0; i15 < 2; i15++) {
        edgelist->data[i15 + edgelist->size[0] * k] = tmp_data[i15];
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i15 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i15, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
  }

  emxFree_int32_T(&r10);

  /* Functioin */
  /* Function */
  for (i15 = 0; i15 < 2; i15++) {
    sedgelist[i15] = (uint32_T)edgelist->size[i15];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(sp, &varargin_1, 2, &l_emlrtRTEI, true);
    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    i15 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = edgelist->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i15, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    d_st.site = &pb_emlrtRSI;
    overflow = (edgelist->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (loop_ub = 0; loop_ub + 1 <= edgelist->size[1]; loop_ub++) {
      ix = (loop_ub << 1) + 2;
      d_st.site = &qb_emlrtRSI;
      n = (loop_ub << 1) + 1;
      mtmp = (int32_T)edgelist->data[ix - 2];
      if (n < ix) {
        e_st.site = &bb_emlrtRSI;
        if ((!(n + 1 > ix)) && (ix > 2147483646)) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (n + 1 <= ix) {
          if ((int32_T)edgelist->data[n] > mtmp) {
            mtmp = (int32_T)edgelist->data[n];
          }

          n++;
        }
      }

      varargin_1->data[loop_ub] = mtmp;
    }

    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    n = varargin_1->size[1];
    mtmp = (int32_T)varargin_1->data[0];
    if (varargin_1->size[1] > 1) {
      e_st.site = &bb_emlrtRSI;
      overflow = (varargin_1->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)varargin_1->data[ix] > mtmp) {
          mtmp = (int32_T)varargin_1->data[ix];
        }
      }
    }

    emxFree_real_T(&varargin_1);
    i15 = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int32_T)sedgelist[1];
    emxEnsureCapacity(sp, (emxArray__common *)inc, i15, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
    loop_ub = mtmp * (int32_T)sedgelist[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      inc->data[i15] = 0.0;
    }

    k = 1;
    while (k - 1 <= (int32_T)sedgelist[1] - 1) {
      i15 = edgelist->size[1];
      if (!((k >= 1) && (k <= i15))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i15, &bc_emlrtBCI, sp);
      }

      ix = inc->size[0];
      n = inc->size[1];
      if (!((k >= 1) && (k <= n))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, n, &cc_emlrtBCI, sp);
      }

      for (i15 = 0; i15 < 2; i15++) {
        mtmp = (int32_T)edgelist->data[i15 + edgelist->size[0] * (k - 1)];
        if (!((mtmp >= 1) && (mtmp <= ix))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, ix, &fc_emlrtBCI, sp);
        }

        inc->data[(mtmp + inc->size[0] * (k - 1)) - 1] = 1.0;
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* For */
  } else {
    i15 = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)inc, i15, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  }

  emxFree_real_T(&edgelist);

  /* If */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void d_DNA2inc(const emlrtStack *sp, const emxArray_real_T *DNA_incstr, const
               emxArray_real_T *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r11;
  boolean_T overflow;
  int32_T i16;
  int32_T loop_ub;
  emxArray_int32_T *r12;
  int32_T ix;
  int32_T n;
  int32_T mtmp;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  uint32_T sedgelist[2];
  emxArray_real_T *varargin_1;
  int32_T k;
  boolean_T x_data[100];
  int32_T ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv23[2];
  int32_T tmp_size[1];
  int32_T tmp_data[100];
  int32_T iv24[1];
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
  emxInit_boolean_T(sp, &r11, 2, &l_emlrtRTEI, true);
  overflow = false;

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  st.site = &q_emlrtRSI;

  /* Function */
  b_st.site = &td_emlrtRSI;

  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  c_st.site = &rd_emlrtRSI;
  i16 = r11->size[0] * r11->size[1];
  r11->size[0] = 1;
  r11->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r11, i16, (int32_T)sizeof
                    (boolean_T), &l_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    r11->data[i16] = (DNA_edgelabel->data[i16] == 4.0);
  }

  emxInit_int32_T(&c_st, &r12, 2, &l_emlrtRTEI, true);
  ix = r11->size[1] - 1;
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r11->data[loop_ub]) {
      n++;
    }
  }

  i16 = r12->size[0] * r12->size[1];
  r12->size[0] = 1;
  r12->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)r12, i16, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r11->data[loop_ub]) {
      r12->data[n] = loop_ub + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r11);
  n = DNA_incstr->size[1];
  loop_ub = r12->size[0] * r12->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    mtmp = r12->data[i16];
    if (!((mtmp >= 1) && (mtmp <= n))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, n, &fe_emlrtBCI, &c_st);
    }
  }

  /* Switch */
  emxInit_real_T(&b_st, &edgelist, 2, &m_emlrtRTEI, true);
  if (!(r12->size[1] == 0)) {
    emxInit_real_T(&b_st, &b_DNA_incstr, 2, &l_emlrtRTEI, true);
    i16 = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = r12->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_DNA_incstr, i16, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    loop_ub = r12->size[0] * r12->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_DNA_incstr->data[i16] = DNA_incstr->data[r12->data[i16] - 1];
    }

    c_st.site = &t_emlrtRSI;
    str2inc(&c_st, b_DNA_incstr, inc);
    n = r12->size[1];
    i16 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i16, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    loop_ub = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i16 = 0; i16 < loop_ub; i16++) {
      edgelist->data[i16] = 0.0;
    }

    k = 0;
    while (k <= inc->size[1] - 1) {
      i16 = edgelist->size[1];
      mtmp = k + 1;
      if (!((mtmp >= 1) && (mtmp <= i16))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i16, &ec_emlrtBCI, &b_st);
      }

      c_st.site = &u_emlrtRSI;
      loop_ub = inc->size[0];
      i16 = inc->size[1];
      mtmp = 1 + k;
      if (!((mtmp >= 1) && (mtmp <= i16))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i16, &dc_emlrtBCI, &c_st);
      }

      for (i16 = 0; i16 < loop_ub; i16++) {
        x_data[i16] = (inc->data[i16 + inc->size[0] * (mtmp - 1)] == 1.0);
      }

      d_st.site = &lb_emlrtRSI;
      n = 0;
      e_st.site = &mb_emlrtRSI;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= loop_ub) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (n <= loop_ub) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &lc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (loop_ub == 1) {
        if (n == 0) {
          loop_ub = 0;
        }
      } else {
        if (1 > n) {
          i16 = 0;
        } else {
          i16 = n;
        }

        iv23[0] = 1;
        iv23[1] = i16;
        e_st.site = &nb_emlrtRSI;
        indexShapeCheck(&e_st, loop_ub, iv23);
        loop_ub = i16;
      }

      tmp_size[0] = loop_ub;
      for (i16 = 0; i16 < loop_ub; i16++) {
        tmp_data[i16] = ii_data[i16];
      }

      if (!overflow) {
        iv24[0] = 2;
        overflow = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv24, 1, tmp_size, 1, &emlrtECI, &b_st);
      for (i16 = 0; i16 < 2; i16++) {
        edgelist->data[i16 + edgelist->size[0] * k] = tmp_data[i16];
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i16 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i16, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
  }

  emxFree_int32_T(&r12);

  /* Functioin */
  /* Function */
  for (i16 = 0; i16 < 2; i16++) {
    sedgelist[i16] = (uint32_T)edgelist->size[i16];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(sp, &varargin_1, 2, &l_emlrtRTEI, true);
    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    i16 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = edgelist->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i16, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    d_st.site = &pb_emlrtRSI;
    overflow = (edgelist->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (loop_ub = 0; loop_ub + 1 <= edgelist->size[1]; loop_ub++) {
      ix = (loop_ub << 1) + 2;
      d_st.site = &qb_emlrtRSI;
      n = (loop_ub << 1) + 1;
      mtmp = (int32_T)edgelist->data[ix - 2];
      if (n < ix) {
        e_st.site = &bb_emlrtRSI;
        if ((!(n + 1 > ix)) && (ix > 2147483646)) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (n + 1 <= ix) {
          if ((int32_T)edgelist->data[n] > mtmp) {
            mtmp = (int32_T)edgelist->data[n];
          }

          n++;
        }
      }

      varargin_1->data[loop_ub] = mtmp;
    }

    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    n = varargin_1->size[1];
    mtmp = (int32_T)varargin_1->data[0];
    if (varargin_1->size[1] > 1) {
      e_st.site = &bb_emlrtRSI;
      overflow = (varargin_1->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)varargin_1->data[ix] > mtmp) {
          mtmp = (int32_T)varargin_1->data[ix];
        }
      }
    }

    emxFree_real_T(&varargin_1);
    i16 = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int32_T)sedgelist[1];
    emxEnsureCapacity(sp, (emxArray__common *)inc, i16, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
    loop_ub = mtmp * (int32_T)sedgelist[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      inc->data[i16] = 0.0;
    }

    k = 1;
    while (k - 1 <= (int32_T)sedgelist[1] - 1) {
      i16 = edgelist->size[1];
      if (!((k >= 1) && (k <= i16))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i16, &bc_emlrtBCI, sp);
      }

      ix = inc->size[0];
      n = inc->size[1];
      if (!((k >= 1) && (k <= n))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, n, &cc_emlrtBCI, sp);
      }

      for (i16 = 0; i16 < 2; i16++) {
        mtmp = (int32_T)edgelist->data[i16 + edgelist->size[0] * (k - 1)];
        if (!((mtmp >= 1) && (mtmp <= ix))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, ix, &fc_emlrtBCI, sp);
        }

        inc->data[(mtmp + inc->size[0] * (k - 1)) - 1] = 1.0;
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* For */
  } else {
    i16 = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)inc, i16, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  }

  emxFree_real_T(&edgelist);

  /* If */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void e_DNA2inc(const emlrtStack *sp, const emxArray_real_T *DNA_incstr, const
               emxArray_real_T *DNA_edgelabel, emxArray_real_T *inc)
{
  emxArray_boolean_T *r16;
  boolean_T overflow;
  int32_T i48;
  int32_T loop_ub;
  emxArray_int32_T *r17;
  int32_T ix;
  int32_T n;
  int32_T mtmp;
  emxArray_real_T *edgelist;
  emxArray_real_T *b_DNA_incstr;
  uint32_T sedgelist[2];
  emxArray_real_T *varargin_1;
  int32_T k;
  boolean_T x_data[100];
  int32_T ii_data[100];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv84[2];
  int32_T tmp_size[1];
  int32_T tmp_data[100];
  int32_T iv85[1];
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
  emxInit_boolean_T(sp, &r16, 2, &l_emlrtRTEI, true);
  overflow = false;

  /*  DNA2inc(DNA,edgetype) returns the incidence matrix that belongs to the */
  /*  specified edgetype It does so according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ... */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible: */
  /*            'H'   -> for hinges */
  /*            'S'   -> for springs */
  /*            'R'   -> for gear ratios */
  /*            'all' -> for complete DNA */
  /*    Output: Incidence matrix */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      % */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  st.site = &q_emlrtRSI;

  /* Function */
  b_st.site = &xg_emlrtRSI;

  /*  DNA2edgelist(DNA,edgetype) returns the edgelist that is defined by the  */
  /*  incidence data of edgetype that are defined by the string. It does so  */
  /*  according to the pattern: */
  /*  */
  /*      1     2     3     4     5     6     7     8     9    10   ...  */
  /*      ------------------------------------------------------- */
  /*      1     1     0     1     0     0     1     0     0     0   ... */
  /*      1     0     1     0     1     0     0     1     0     0   ... */
  /*      0     1     1     0     0     1     0     0     1     0   ... */
  /*      0     0     0     1     1     1     0     0     0     1   ... */
  /*      0     0     0     0     0     0     1     1     1     1   ... */
  /*  */
  /*    Input:  DNA and edgetype, currently three options are possible:  */
  /*            'H'   -> for hinges        */
  /*            'S'   -> for springs       */
  /*            'all' -> for complete DNA */
  /*    Output: 2xN vector containing the vertices that are connected in its */
  /*            columns  */
  /*  */
  /*  % % % % DNA2edgelist(DNA,edgetype,data) returns the edgelist that is defined by  */
  /*  % % % % the incidence data of edgetype + aditional data of choice. */
  /*  % % % % */
  /*  % % % %   Input:  DNA,edgetype,data, currently three options are possible */
  /*  % % % %           'lab'       -> adds labels  */
  /*  % % % %           'par'       -> adds parameters     */
  /*  % % % %           'lab+par'   -> adds both labels and parameters */
  /*  % % % % */
  /*  % % % %   Output: depending on the input 'data' a differently sized matrix with */
  /*  % % % %   the data */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 30-06-2015                                             % */
  /*    Last modified: 30-06-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  c_st.site = &rd_emlrtRSI;
  i48 = r16->size[0] * r16->size[1];
  r16->size[0] = 1;
  r16->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r16, i48, (int32_T)sizeof
                    (boolean_T), &l_emlrtRTEI);
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i48 = 0; i48 < loop_ub; i48++) {
    r16->data[i48] = (DNA_edgelabel->data[i48] == 2.0);
  }

  emxInit_int32_T(&c_st, &r17, 2, &l_emlrtRTEI, true);
  ix = r16->size[1] - 1;
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r16->data[loop_ub]) {
      n++;
    }
  }

  i48 = r17->size[0] * r17->size[1];
  r17->size[0] = 1;
  r17->size[1] = n;
  emxEnsureCapacity(&c_st, (emxArray__common *)r17, i48, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  n = 0;
  for (loop_ub = 0; loop_ub <= ix; loop_ub++) {
    if (r16->data[loop_ub]) {
      r17->data[n] = loop_ub + 1;
      n++;
    }
  }

  emxFree_boolean_T(&r16);
  n = DNA_incstr->size[1];
  loop_ub = r17->size[0] * r17->size[1];
  for (i48 = 0; i48 < loop_ub; i48++) {
    mtmp = r17->data[i48];
    if (!((mtmp >= 1) && (mtmp <= n))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, n, &wh_emlrtBCI, &c_st);
    }
  }

  /* Switch */
  emxInit_real_T(&b_st, &edgelist, 2, &m_emlrtRTEI, true);
  if (!(r17->size[1] == 0)) {
    emxInit_real_T(&b_st, &b_DNA_incstr, 2, &l_emlrtRTEI, true);
    i48 = b_DNA_incstr->size[0] * b_DNA_incstr->size[1];
    b_DNA_incstr->size[0] = 1;
    b_DNA_incstr->size[1] = r17->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_DNA_incstr, i48, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    loop_ub = r17->size[0] * r17->size[1];
    for (i48 = 0; i48 < loop_ub; i48++) {
      b_DNA_incstr->data[i48] = DNA_incstr->data[r17->data[i48] - 1];
    }

    c_st.site = &t_emlrtRSI;
    str2inc(&c_st, b_DNA_incstr, inc);
    n = r17->size[1];
    i48 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = n;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i48, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
    loop_ub = n << 1;
    emxFree_real_T(&b_DNA_incstr);
    for (i48 = 0; i48 < loop_ub; i48++) {
      edgelist->data[i48] = 0.0;
    }

    k = 0;
    while (k <= inc->size[1] - 1) {
      i48 = edgelist->size[1];
      mtmp = k + 1;
      if (!((mtmp >= 1) && (mtmp <= i48))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i48, &ec_emlrtBCI, &b_st);
      }

      c_st.site = &u_emlrtRSI;
      loop_ub = inc->size[0];
      i48 = inc->size[1];
      mtmp = 1 + k;
      if (!((mtmp >= 1) && (mtmp <= i48))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, i48, &dc_emlrtBCI, &c_st);
      }

      for (i48 = 0; i48 < loop_ub; i48++) {
        x_data[i48] = (inc->data[i48 + inc->size[0] * (mtmp - 1)] == 1.0);
      }

      d_st.site = &lb_emlrtRSI;
      n = 0;
      e_st.site = &mb_emlrtRSI;
      ix = 1;
      exitg1 = false;
      while ((!exitg1) && (ix <= loop_ub)) {
        guard1 = false;
        if (x_data[ix - 1]) {
          n++;
          ii_data[n - 1] = ix;
          if (n >= loop_ub) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ix++;
        }
      }

      if (n <= loop_ub) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &lc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (loop_ub == 1) {
        if (n == 0) {
          loop_ub = 0;
        }
      } else {
        if (1 > n) {
          i48 = 0;
        } else {
          i48 = n;
        }

        iv84[0] = 1;
        iv84[1] = i48;
        e_st.site = &nb_emlrtRSI;
        indexShapeCheck(&e_st, loop_ub, iv84);
        loop_ub = i48;
      }

      tmp_size[0] = loop_ub;
      for (i48 = 0; i48 < loop_ub; i48++) {
        tmp_data[i48] = ii_data[i48];
      }

      if (!overflow) {
        iv85[0] = 2;
        overflow = true;
      }

      emlrtSubAssignSizeCheckR2012b(iv85, 1, tmp_size, 1, &emlrtECI, &b_st);
      for (i48 = 0; i48 < 2; i48++) {
        edgelist->data[i48 + edgelist->size[0] * k] = tmp_data[i48];
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    /*  if isempty(edgelist) */
    /*      edgelist = zeros(0,2); */
    /*  end */
  } else {
    i48 = edgelist->size[0] * edgelist->size[1];
    edgelist->size[0] = 2;
    edgelist->size[1] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)edgelist, i48, (int32_T)sizeof
                      (real_T), &l_emlrtRTEI);
  }

  emxFree_int32_T(&r17);

  /* Functioin */
  /* Function */
  for (i48 = 0; i48 < 2; i48++) {
    sedgelist[i48] = (uint32_T)edgelist->size[i48];
  }

  if (!(edgelist->size[1] == 0)) {
    emxInit_real_T(sp, &varargin_1, 2, &l_emlrtRTEI, true);
    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    i48 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = edgelist->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)varargin_1, i48, (int32_T)
                      sizeof(real_T), &l_emlrtRTEI);
    d_st.site = &pb_emlrtRSI;
    overflow = (edgelist->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (loop_ub = 0; loop_ub + 1 <= edgelist->size[1]; loop_ub++) {
      ix = (loop_ub << 1) + 2;
      d_st.site = &qb_emlrtRSI;
      n = (loop_ub << 1) + 1;
      mtmp = (int32_T)edgelist->data[ix - 2];
      if (n < ix) {
        e_st.site = &bb_emlrtRSI;
        if ((!(n + 1 > ix)) && (ix > 2147483646)) {
          f_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (n + 1 <= ix) {
          if ((int32_T)edgelist->data[n] > mtmp) {
            mtmp = (int32_T)edgelist->data[n];
          }

          n++;
        }
      }

      varargin_1->data[loop_ub] = mtmp;
    }

    st.site = &r_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    n = varargin_1->size[1];
    mtmp = (int32_T)varargin_1->data[0];
    if (varargin_1->size[1] > 1) {
      e_st.site = &bb_emlrtRSI;
      overflow = (varargin_1->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)varargin_1->data[ix] > mtmp) {
          mtmp = (int32_T)varargin_1->data[ix];
        }
      }
    }

    emxFree_real_T(&varargin_1);
    i48 = inc->size[0] * inc->size[1];
    inc->size[0] = mtmp;
    inc->size[1] = (int32_T)sedgelist[1];
    emxEnsureCapacity(sp, (emxArray__common *)inc, i48, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
    loop_ub = mtmp * (int32_T)sedgelist[1];
    for (i48 = 0; i48 < loop_ub; i48++) {
      inc->data[i48] = 0.0;
    }

    k = 1;
    while (k - 1 <= (int32_T)sedgelist[1] - 1) {
      i48 = edgelist->size[1];
      if (!((k >= 1) && (k <= i48))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i48, &bc_emlrtBCI, sp);
      }

      ix = inc->size[0];
      n = inc->size[1];
      if (!((k >= 1) && (k <= n))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, n, &cc_emlrtBCI, sp);
      }

      for (i48 = 0; i48 < 2; i48++) {
        mtmp = (int32_T)edgelist->data[i48 + edgelist->size[0] * (k - 1)];
        if (!((mtmp >= 1) && (mtmp <= ix))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, ix, &fc_emlrtBCI, sp);
        }

        inc->data[(mtmp + inc->size[0] * (k - 1)) - 1] = 1.0;
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* For */
  } else {
    i48 = inc->size[0] * inc->size[1];
    inc->size[0] = 0;
    inc->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)inc, i48, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  }

  emxFree_real_T(&edgelist);

  /* If */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (DNA2inc.c) */
