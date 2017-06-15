/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * str2inc.c
 *
 * Code generation for function 'str2inc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "str2inc.h"
#include "simulateDNA_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "eye.h"
#include "simulateDNA_mexutil.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 4, "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m"
};

static emlrtRSInfo w_emlrtRSI = { 5, "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m"
};

static emlrtRSInfo eb_emlrtRSI = { 31, "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m"
};

static emlrtRSInfo fb_emlrtRSI = { 40, "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m"
};

static emlrtRSInfo gb_emlrtRSI = { 22, "nCr",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\nCr.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 2, 16, "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 5, 1, "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m"
};

static emlrtECInfo b_emlrtECI = { -1, 40, 5, "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m"
};

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 40, 10, "M", "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 40, 52, "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m",
  4 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 6, 11, "M", "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 6, 11, "str2inc",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\str2inc.m",
  1 };

static emlrtBCInfo ic_emlrtBCI = { 1, 100, 31, 5, "b", "incPattern2",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\incPattern2.m",
  0 };

/* Function Definitions */
void str2inc(const emlrtStack *sp, const emxArray_real_T *str, emxArray_real_T
             *mat)
{
  boolean_T overflow;
  int32_T ixstart;
  int32_T n;
  real_T mtmp;
  int32_T ix;
  boolean_T exitg1;
  real_T nComb;
  int32_T c;
  int16_T b[100];
  emxArray_real_T *M;
  int32_T i5;
  int32_T loop_ub;
  int32_T k;
  emxArray_real_T *r1;
  emxArray_real_T *varargin_1;
  cell_wrap_0 reshapes[3];
  emxArray_real_T *r2;
  int32_T i6;
  int32_T i7;
  char_T u[91];
  static const char_T b_varargin_1[91] = { 'n', 'C', 'r', ' ', 'c', 'o', 'n',
    't', 'a', 'i', 'n', 's', ' ', 'a', ' ', 'l', 'i', 's', 't', ' ', 'w', 'i',
    't', 'h', ' ', '1', '0', '0', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's',
    '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't',
    ' ', 'n', '<', '1', '0', '0', ' ', 'o', 'r', ' ', 'a', 'd', 'd', ' ', 'm',
    'o', 'r', 'e', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', ' ', 't', 'o',
    ' ', 't', 'h', 'e', ' ', 'l', 'i', 's', 't' };

  int32_T b_loop_ub;
  int32_T tmp_data[100];
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv4[2] = { 1, 91 };

  int32_T b_tmp_data[4950];
  static const int16_T A000217[100] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55,
    66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351,
    378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861,
    903, 946, 990, 1035, 1081, 1128, 1176, 1225, 1275, 1326, 1378, 1431, 1485,
    1540, 1596, 1653, 1711, 1770, 1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278,
    2346, 2415, 2485, 2556, 2628, 2701, 2775, 2850, 2926, 3003, 3081, 3160, 3240,
    3321, 3403, 3486, 3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186, 4278, 4371,
    4465, 4560, 4656, 4753, 4851, 4950 };

  int32_T result;
  int32_T iv5[2];
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
  st.site = &v_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if ((str->size[1] == 1) || (str->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &mc_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (str->size[1] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &oc_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &ab_emlrtRSI;
  ixstart = 1;
  n = str->size[1];
  mtmp = str->data[0];
  if (str->size[1] > 1) {
    if (muDoubleScalarIsNaN(str->data[0])) {
      e_st.site = &cb_emlrtRSI;
      overflow = (str->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(str->data[ix - 1])) {
          mtmp = str->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < str->size[1]) {
      e_st.site = &bb_emlrtRSI;
      overflow = ((!(ixstart + 1 > str->size[1])) && (str->size[1] > 2147483646));
      if (overflow) {
        f_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (str->data[ixstart] > mtmp) {
          mtmp = str->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  st.site = &w_emlrtRSI;

  /*    M = GenCombinationMatrix(nCol) generates a matrix with all combinations */
  /*    up to at least nCol columns.  */
  /*     */
  /*    [M,v] = GenCombinationMatrix(nCol) generates a matrix with all */
  /*    combinations up to at least nE collumns and returns the minimum number */
  /*    of vertices required. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*                                                                          % */
  /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
  /*    Original Date: 26-05-2015                                             % */
  /*    Last modified: 26-05-2015                                             % */
  /*                                                                          % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  nComb = 0.0;

  /* Total number of columns in the combination matrix */
  c = 0;

  /* Set counter to zero   */
  memset(&b[0], 0, 100U * sizeof(int16_T));
  while (nComb < mtmp) {
    /* While the Total number of columns is lower that the desired number */
    c++;

    /* Increase counter */
    b_st.site = &eb_emlrtRSI;

    /*    C = nCr(n,k) returns the number of combinations with */
    /*     */
    /*    n the number of values to pick from  */
    /*    k the number of picks */
    /*  */
    /*    with the formula: n!/(k!(n-k)!) */
    /*  */
    /*    Be aware that the factorial function can only be used up to n = 170,  */
    /*    because of machine precision. 170!=7.2574*10^306 to give an idea  */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*                                                                          % */
    /*    Written by Reinier Kuppens as part of Msc Thesis                      %            */
    /*    Original Date: 26-05-2015                                             % */
    /*    Last modified: 29-06-2015                                             % */
    /*                                                                          % */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    if (c + 1 > 100) {
      c_st.site = &gb_emlrtRSI;
      memcpy(&u[0], &b_varargin_1[0], 91U * sizeof(char_T));
      y = NULL;
      m0 = emlrtCreateCharArray(2, iv4);
      emlrtInitCharArrayR2013a(&c_st, 91, m0, &u[0]);
      emlrtAssign(&y, m0);
      d_st.site = &nh_emlrtRSI;
      g_error(&d_st, y, &emlrtMCI);
    }

    /* nCr is a function that is called many times in the EA. Therefore, no matter */
    /* what function I used to compute the number of ways to pick k form n, it's */
    /* self time was one of the largest. Because of this we simply use a list. */
    /* See https://oeis.org/A000217 for the sequence. */
    /*  VChooseK is a mex file. */
    /*  */
    /*    For speed cast the input to integer types if possible: */
    /*      Y = double(VChooseK(int16(1:1000), 2); */
    /*    is faster than: */
    /*      Y = VChooseK(1:1000, 2); */
    /*  */
    /*  For details on VChooseK see doc in toolbox folder */
    /*  if n>=k */
    /*      Cmat    = double(VChooseK(int16(1:n),k)); */
    /*      C       = size(Cmat,1); */
    /*  %     C = nchoosek(n,k);%SLOW */
    /*  else */
    /*      C = 0; */
    /*  end */
    if (!((c + 1 >= 1) && (c + 1 <= 100))) {
      emlrtDynamicBoundsCheckR2012b(c + 1, 1, 100, &ic_emlrtBCI, &st);
    }

    b[c] = A000217[c];
    nComb += (real_T)(b[c] - b[c - 1]);

    /* Add collumns: (nCr(c,2)-nCr(c-1,2)) per vertices */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxInit_real_T(&st, &M, 2, &o_emlrtRTEI, true);

  /* Set counter equal to number of vertices */
  i5 = M->size[0] * M->size[1];
  M->size[0] = c + 1;
  M->size[1] = b[c];
  emxEnsureCapacity(&st, (emxArray__common *)M, i5, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  loop_ub = (c + 1) * b[c];
  for (i5 = 0; i5 < loop_ub; i5++) {
    M->data[i5] = 0.0;
  }

  k = 1;
  emxInit_real_T(&st, &r1, 2, &n_emlrtRTEI, true);
  emxInit_real_T(&st, &varargin_1, 2, &n_emlrtRTEI, true);
  emxInitMatrix_cell_wrap_0(&st, reshapes, &p_emlrtRTEI, true);
  emxInit_real_T(&st, &r2, 2, &n_emlrtRTEI, true);
  while (k - 1 <= c - 1) {
    if (b[k - 1] + 1 > b[k]) {
      i5 = 0;
      i7 = 0;
    } else {
      i5 = M->size[1];
      i6 = b[k - 1] + 1;
      if (!((i6 >= 1) && (i6 <= i5))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &gc_emlrtBCI, &st);
      }

      i5 = i6 - 1;
      i6 = M->size[1];
      i7 = b[k];
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &gc_emlrtBCI, &st);
      }
    }

    loop_ub = M->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tmp_data[i6] = i6;
    }

    b_loop_ub = i7 - i5;
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      b_tmp_data[i6] = i5 + i6;
    }

    b_st.site = &fb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    eye(&c_st, 1.0 + (real_T)(k - 1), r2);
    i6 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = r2->size[0];
    varargin_1->size[1] = r2->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i6, (int32_T)sizeof
                      (real_T), &n_emlrtRTEI);
    b_loop_ub = r2->size[0] * r2->size[1];
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      varargin_1->data[i6] = r2->data[i6];
    }

    mtmp = (real_T)((c - k) + 1) - 1.0;
    if (!(mtmp >= 0.0)) {
      emlrtNonNegativeCheckR2012b(mtmp, &b_emlrtDCI, &b_st);
    }

    c_st.site = &jb_emlrtRSI;
    if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))) {
      n = varargin_1->size[1];
    } else {
      n = k;
    }

    d_st.site = &kb_emlrtRSI;
    if ((n == varargin_1->size[1]) || ((varargin_1->size[0] == 0) ||
         (varargin_1->size[1] == 0))) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &nc_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if (n == k) {
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &nc_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if ((n == k) || (c - k == 0)) {
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &nc_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    overflow = (n == 0);
    if (overflow || (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))))
    {
      result = varargin_1->size[0];
    } else {
      result = 0;
    }

    i6 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)reshapes[1].f1, i6, (int32_T)
                      sizeof(real_T), &n_emlrtRTEI);
    for (i6 = 0; i6 < n; i6++) {
      reshapes[1].f1->data[i6] = 1.0;
    }

    if (overflow || (!(c - k == 0))) {
      ixstart = c - k;
    } else {
      ixstart = 0;
    }

    i6 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = ixstart;
    reshapes[2].f1->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)reshapes[2].f1, i6, (int32_T)
                      sizeof(real_T), &n_emlrtRTEI);
    b_loop_ub = ixstart * n;
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      reshapes[2].f1->data[i6] = 0.0;
    }

    i6 = r1->size[0] * r1->size[1];
    r1->size[0] = (result + reshapes[1].f1->size[0]) + reshapes[2].f1->size[0];
    r1->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)r1, i6, (int32_T)sizeof(real_T),
                      &n_emlrtRTEI);
    for (i6 = 0; i6 < n; i6++) {
      for (ix = 0; ix < result; ix++) {
        r1->data[ix + r1->size[0] * i6] = varargin_1->data[ix + result * i6];
      }
    }

    b_loop_ub = reshapes[1].f1->size[1];
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      ixstart = reshapes[1].f1->size[0];
      for (ix = 0; ix < ixstart; ix++) {
        r1->data[(ix + result) + r1->size[0] * i6] = reshapes[1].f1->data[ix +
          reshapes[1].f1->size[0] * i6];
      }
    }

    b_loop_ub = reshapes[2].f1->size[1];
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      ixstart = reshapes[2].f1->size[0];
      for (ix = 0; ix < ixstart; ix++) {
        r1->data[((ix + result) + reshapes[1].f1->size[0]) + r1->size[0] * i6] =
          reshapes[2].f1->data[ix + reshapes[2].f1->size[0] * i6];
      }
    }

    iv5[0] = loop_ub;
    iv5[1] = i7 - i5;
    emlrtSubAssignSizeCheckR2012b(iv5, 2, *(int32_T (*)[2])r1->size, 2,
      &b_emlrtECI, &st);
    loop_ub = r1->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_loop_ub = r1->size[0];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        M->data[tmp_data[i6] + M->size[0] * b_tmp_data[i5]] = r1->data[i6 +
          r1->size[0] * i5];
      }
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&r2);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&r1);
  loop_ub = M->size[0];
  ixstart = M->size[1];
  i5 = mat->size[0] * mat->size[1];
  mat->size[0] = loop_ub;
  mat->size[1] = str->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)mat, i5, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  b_loop_ub = str->size[1];
  for (i5 = 0; i5 < b_loop_ub; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      mtmp = str->data[str->size[0] * i5];
      if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
        emlrtIntegerCheckR2012b(mtmp, &c_emlrtDCI, sp);
      }

      i7 = (int32_T)mtmp;
      if (!((i7 >= 1) && (i7 <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, ixstart, &hc_emlrtBCI, sp);
      }

      mat->data[i6 + mat->size[0] * i5] = M->data[i6 + M->size[0] * (i7 - 1)];
    }
  }

  emxFree_real_T(&M);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (str2inc.c) */
