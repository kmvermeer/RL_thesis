/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: str2inc.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "str2inc.h"
#include "simulateDNA_emxutil.h"
#include "eye.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *str
 *                emxArray_real_T *mat
 * Return Type  : void
 */
void str2inc(const emxArray_real_T *str, emxArray_real_T *mat)
{
  int ixstart;
  int n;
  double mtmp;
  int ix;
  boolean_T exitg1;
  double nComb;
  int c;
  short b[100];
  emxArray_real_T *M;
  int i3;
  int k;
  emxArray_real_T *varargin_1;
  emxArray_real_T *r4;
  emxArray_real_T *r5;
  int i4;
  boolean_T empty_non_axis_sizes;
  int c_idx_0;
  static const short A000217[100] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66,
    78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378,
    406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903,
    946, 990, 1035, 1081, 1128, 1176, 1225, 1275, 1326, 1378, 1431, 1485, 1540,
    1596, 1653, 1711, 1770, 1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278, 2346,
    2415, 2485, 2556, 2628, 2701, 2775, 2850, 2926, 3003, 3081, 3160, 3240, 3321,
    3403, 3486, 3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186, 4278, 4371, 4465,
    4560, 4656, 4753, 4851, 4950 };

  int i5;
  ixstart = 1;
  n = str->size[1];
  mtmp = str->data[0];
  if (str->size[1] > 1) {
    if (rtIsNaN(str->data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(str->data[ix - 1])) {
          mtmp = str->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < str->size[1]) {
      while (ixstart + 1 <= n) {
        if (str->data[ixstart] > mtmp) {
          mtmp = str->data[ixstart];
        }

        ixstart++;
      }
    }
  }

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
  memset(&b[0], 0, 100U * sizeof(short));
  while (nComb < mtmp) {
    /* While the Total number of columns is lower that the desired number */
    c++;

    /* Increase counter */
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
    b[c] = A000217[c];
    nComb += (double)(b[c] - b[c - 1]);

    /* Add collumns: (nCr(c,2)-nCr(c-1,2)) per vertices */
  }

  emxInit_real_T(&M, 2);

  /* Set counter equal to number of vertices */
  i3 = M->size[0] * M->size[1];
  M->size[0] = c + 1;
  M->size[1] = b[c];
  emxEnsureCapacity((emxArray__common *)M, i3, (int)sizeof(double));
  n = (c + 1) * b[c];
  for (i3 = 0; i3 < n; i3++) {
    M->data[i3] = 0.0;
  }

  k = 1;
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&r4, 2);
  emxInit_real_T(&r5, 2);
  while (k - 1 <= c - 1) {
    if (b[k - 1] + 1 > b[k]) {
      i3 = 1;
    } else {
      i3 = b[k - 1] + 1;
    }

    eye(1.0 + (double)(k - 1), r4);
    i4 = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = r4->size[0];
    varargin_1->size[1] = r4->size[1];
    emxEnsureCapacity((emxArray__common *)varargin_1, i4, (int)sizeof(double));
    n = r4->size[0] * r4->size[1];
    for (i4 = 0; i4 < n; i4++) {
      varargin_1->data[i4] = r4->data[i4];
    }

    if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))) {
      ixstart = varargin_1->size[1];
    } else {
      ixstart = k;
    }

    empty_non_axis_sizes = (ixstart == 0);
    if (empty_non_axis_sizes || (!((varargin_1->size[0] == 0) ||
          (varargin_1->size[1] == 0)))) {
      n = varargin_1->size[0];
    } else {
      n = 0;
    }

    if (empty_non_axis_sizes || (!(c - k == 0))) {
      ix = c - k;
    } else {
      ix = 0;
    }

    c_idx_0 = c - k;
    i4 = r5->size[0] * r5->size[1];
    r5->size[0] = c_idx_0;
    r5->size[1] = k;
    emxEnsureCapacity((emxArray__common *)r5, i4, (int)sizeof(double));
    for (i4 = 0; i4 < k; i4++) {
      for (i5 = 0; i5 < c_idx_0; i5++) {
        r5->data[i5 + r5->size[0] * i4] = 0.0;
      }
    }

    for (i4 = 0; i4 < ixstart; i4++) {
      for (i5 = 0; i5 < n; i5++) {
        M->data[i5 + M->size[0] * ((i3 + i4) - 1)] = varargin_1->data[i5 + n *
          i4];
      }
    }

    for (i4 = 0; i4 < ixstart; i4++) {
      for (i5 = 0; i5 < 1; i5++) {
        M->data[n + M->size[0] * ((i3 + i4) - 1)] = 1.0;
      }
    }

    for (i4 = 0; i4 < ixstart; i4++) {
      for (i5 = 0; i5 < ix; i5++) {
        M->data[((i5 + n) + M->size[0] * ((i3 + i4) - 1)) + 1] = r5->data[i5 +
          ix * i4];
      }
    }

    k++;
  }

  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&varargin_1);
  n = M->size[0];
  i3 = mat->size[0] * mat->size[1];
  mat->size[0] = n;
  mat->size[1] = str->size[1];
  emxEnsureCapacity((emxArray__common *)mat, i3, (int)sizeof(double));
  ixstart = str->size[1];
  for (i3 = 0; i3 < ixstart; i3++) {
    for (i4 = 0; i4 < n; i4++) {
      mat->data[i4 + mat->size[0] * i3] = M->data[i4 + M->size[0] * ((int)
        str->data[str->size[0] * i3] - 1)];
    }
  }

  emxFree_real_T(&M);
}

/*
 * File trailer for str2inc.c
 *
 * [EOF]
 */
