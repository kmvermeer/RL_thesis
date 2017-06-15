/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mrdivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "mrdivide.h"
#include "simulateDNA_emxutil.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "xgeqp3.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *A
 *                const emxArray_real_T *B
 * Return Type  : void
 */
void mrdivide(emxArray_real_T *A, const emxArray_real_T *B)
{
  emxArray_real_T *Y;
  emxArray_real_T *b_B;
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *c_B;
  int jBcol;
  int j;
  int n;
  int m;
  int mn;
  int nb;
  int k;
  double wj;
  int i;
  emxInit_real_T(&Y, 2);
  emxInit_real_T(&b_B, 2);
  emxInit_real_T(&b_A, 2);
  emxInit_real_T1(&tau, 1);
  emxInit_int32_T1(&jpvt, 2);
  emxInit_real_T(&c_B, 2);
  if ((A->size[0] == 0) || (A->size[1] == 0) || ((B->size[0] == 0) || (B->size[1]
        == 0))) {
    jBcol = A->size[0];
    m = B->size[0];
    j = A->size[0] * A->size[1];
    A->size[0] = jBcol;
    A->size[1] = m;
    emxEnsureCapacity((emxArray__common *)A, j, (int)sizeof(double));
    for (j = 0; j < m; j++) {
      for (mn = 0; mn < jBcol; mn++) {
        A->data[mn + A->size[0] * j] = 0.0;
      }
    }
  } else if (B->size[0] == B->size[1]) {
    n = B->size[1];
    j = b_A->size[0] * b_A->size[1];
    b_A->size[0] = B->size[0];
    b_A->size[1] = B->size[1];
    emxEnsureCapacity((emxArray__common *)b_A, j, (int)sizeof(double));
    m = B->size[0] * B->size[1];
    for (j = 0; j < m; j++) {
      b_A->data[j] = B->data[j];
    }

    xgetrf(B->size[1], B->size[1], b_A, B->size[1], jpvt, &jBcol);
    nb = A->size[0];
    if ((A->size[0] == 0) || (A->size[1] == 0)) {
    } else {
      for (j = 0; j + 1 <= n; j++) {
        jBcol = nb * j;
        m = n * j;
        for (k = 0; k + 1 <= j; k++) {
          mn = nb * k;
          if (b_A->data[k + m] != 0.0) {
            for (i = 0; i + 1 <= nb; i++) {
              A->data[i + jBcol] -= b_A->data[k + m] * A->data[i + mn];
            }
          }
        }

        wj = b_A->data[j + m];
        wj = 1.0 / wj;
        for (i = 0; i + 1 <= nb; i++) {
          A->data[i + jBcol] *= wj;
        }
      }
    }

    if ((A->size[0] == 0) || (A->size[1] == 0)) {
    } else {
      for (j = B->size[1]; j > 0; j--) {
        jBcol = nb * (j - 1);
        m = n * (j - 1);
        for (k = j; k + 1 <= n; k++) {
          mn = nb * k;
          if (b_A->data[k + m] != 0.0) {
            for (i = 0; i + 1 <= nb; i++) {
              A->data[i + jBcol] -= b_A->data[k + m] * A->data[i + mn];
            }
          }
        }
      }
    }

    for (jBcol = B->size[1] - 2; jBcol + 1 > 0; jBcol--) {
      if (jpvt->data[jBcol] != jBcol + 1) {
        m = jpvt->data[jBcol] - 1;
        for (mn = 0; mn + 1 <= nb; mn++) {
          wj = A->data[mn + A->size[0] * jBcol];
          A->data[mn + A->size[0] * jBcol] = A->data[mn + A->size[0] * m];
          A->data[mn + A->size[0] * m] = wj;
        }
      }
    }
  } else {
    j = b_B->size[0] * b_B->size[1];
    b_B->size[0] = A->size[1];
    b_B->size[1] = A->size[0];
    emxEnsureCapacity((emxArray__common *)b_B, j, (int)sizeof(double));
    m = A->size[0];
    for (j = 0; j < m; j++) {
      jBcol = A->size[1];
      for (mn = 0; mn < jBcol; mn++) {
        b_B->data[mn + b_B->size[0] * j] = A->data[j + A->size[0] * mn];
      }
    }

    j = b_A->size[0] * b_A->size[1];
    b_A->size[0] = B->size[1];
    b_A->size[1] = B->size[0];
    emxEnsureCapacity((emxArray__common *)b_A, j, (int)sizeof(double));
    m = B->size[0];
    for (j = 0; j < m; j++) {
      jBcol = B->size[1];
      for (mn = 0; mn < jBcol; mn++) {
        b_A->data[mn + b_A->size[0] * j] = B->data[j + B->size[0] * mn];
      }
    }

    xgeqp3(b_A, tau, jpvt);
    n = rankFromQR(b_A);
    jBcol = b_A->size[1];
    m = b_B->size[1];
    j = Y->size[0] * Y->size[1];
    Y->size[0] = jBcol;
    Y->size[1] = m;
    emxEnsureCapacity((emxArray__common *)Y, j, (int)sizeof(double));
    m *= jBcol;
    for (j = 0; j < m; j++) {
      Y->data[j] = 0.0;
    }

    j = c_B->size[0] * c_B->size[1];
    c_B->size[0] = b_B->size[0];
    c_B->size[1] = b_B->size[1];
    emxEnsureCapacity((emxArray__common *)c_B, j, (int)sizeof(double));
    m = b_B->size[0] * b_B->size[1];
    for (j = 0; j < m; j++) {
      c_B->data[j] = b_B->data[j];
    }

    m = b_A->size[0];
    jBcol = b_A->size[0];
    mn = b_A->size[1];
    if (jBcol <= mn) {
      mn = jBcol;
    }

    for (j = 0; j + 1 <= mn; j++) {
      if (tau->data[j] != 0.0) {
        for (k = 0; k + 1 <= b_B->size[1]; k++) {
          wj = c_B->data[j + c_B->size[0] * k];
          for (i = j + 1; i + 1 <= m; i++) {
            wj += b_A->data[i + b_A->size[0] * j] * c_B->data[i + c_B->size[0] *
              k];
          }

          wj *= tau->data[j];
          if (wj != 0.0) {
            c_B->data[j + c_B->size[0] * k] -= wj;
            for (i = j + 1; i + 1 <= m; i++) {
              c_B->data[i + c_B->size[0] * k] -= b_A->data[i + b_A->size[0] * j]
                * wj;
            }
          }
        }
      }
    }

    for (k = 0; k + 1 <= b_B->size[1]; k++) {
      for (i = 0; i + 1 <= n; i++) {
        Y->data[(jpvt->data[i] + Y->size[0] * k) - 1] = c_B->data[i + c_B->size
          [0] * k];
      }

      for (j = n - 1; j + 1 > 0; j--) {
        Y->data[(jpvt->data[j] + Y->size[0] * k) - 1] /= b_A->data[j + b_A->
          size[0] * j];
        for (i = 0; i + 1 <= j; i++) {
          Y->data[(jpvt->data[i] + Y->size[0] * k) - 1] -= Y->data[(jpvt->data[j]
            + Y->size[0] * k) - 1] * b_A->data[i + b_A->size[0] * j];
        }
      }
    }

    j = A->size[0] * A->size[1];
    A->size[0] = Y->size[1];
    A->size[1] = Y->size[0];
    emxEnsureCapacity((emxArray__common *)A, j, (int)sizeof(double));
    m = Y->size[0];
    for (j = 0; j < m; j++) {
      jBcol = Y->size[1];
      for (mn = 0; mn < jBcol; mn++) {
        A->data[mn + A->size[0] * j] = Y->data[j + Y->size[0] * mn];
      }
    }
  }

  emxFree_real_T(&c_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&b_A);
  emxFree_real_T(&b_B);
  emxFree_real_T(&Y);
}

/*
 * File trailer for mrdivide.c
 *
 * [EOF]
 */
