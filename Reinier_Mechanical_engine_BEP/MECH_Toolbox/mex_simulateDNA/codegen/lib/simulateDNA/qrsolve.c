/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: qrsolve.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "qrsolve.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 * Return Type  : int
 */
int rankFromQR(const emxArray_real_T *A)
{
  int r;
  int minmn;
  int maxmn;
  double tol;
  r = 0;
  if (A->size[0] < A->size[1]) {
    minmn = A->size[0];
    maxmn = A->size[1];
  } else {
    minmn = A->size[1];
    maxmn = A->size[0];
  }

  if (minmn > 0) {
    tol = (double)maxmn * fabs(A->data[0]) * 2.2204460492503131E-16;
    while ((r < minmn) && (fabs(A->data[r + A->size[0] * r]) >= tol)) {
      r++;
    }
  }

  return r;
}

/*
 * File trailer for qrsolve.c
 *
 * [EOF]
 */
