/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: simulateDNA.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "simulateDNA_emxutil.h"
#include "any.h"
#include "eom.h"
#include "getCompoints.h"

/* Function Definitions */

/*
 * Arguments    : const struct0_T *DNA
 *                double T
 *                double h
 *                emxArray_real_T *t
 *                emxArray_real_T *qss
 *                double *flag
 * Return Type  : void
 */
void simulateDNA(const struct0_T *DNA, double T, double h, emxArray_real_T *t,
                 emxArray_real_T *qss, double *flag)
{
  emxArray_real_T *x0;
  emxArray_real_T *comPoints;
  int i0;
  int unnamed_idx_1;
  int nm1d2;
  int k;
  emxArray_real_T *r0;
  int n;
  emxArray_real_T *ynew;
  double nx0;
  int b_flag;
  double b_t;
  double anew;
  double apnd;
  double ndbl;
  emxArray_real_T *r1;
  double cdiff;
  emxArray_int32_T *r2;
  emxArray_real_T *b_x0;
  emxArray_real_T *s1;
  emxArray_real_T *s2;
  emxArray_real_T *s3;
  emxArray_real_T *s4;
  emxArray_boolean_T *x;
  emxArray_boolean_T *r3;
  emxArray_real_T *b_ynew;
  emxArray_real_T *c_ynew;
  emxArray_real_T *d_ynew;
  emxArray_real_T *e_ynew;
  boolean_T guard1 = false;
  int exitg1;
  double tnew;
  boolean_T y;
  boolean_T exitg2;
  boolean_T b0;
  emxInit_real_T(&x0, 2);
  emxInit_real_T(&comPoints, 2);

  /* simulateDNA - computes the states of the mechanism represented by DNA. The */
  /* mex-version of this function is used in the EA. When compiling the */
  /* functions getCompoints.m and getDk.m should be checked not to contain */
  /* getInc_mex. */
  getCompoints(DNA->incstr, DNA->edgelabel, DNA->Mpar, DNA->Hpar, DNA->Spar,
               DNA->Ppar, DNA->Pmpar, comPoints);

  /* body boundaries and com */
  i0 = comPoints->size[0];
  unnamed_idx_1 = comPoints->size[0];
  nm1d2 = x0->size[0] * x0->size[1];
  x0->size[0] = 1;
  x0->size[1] = (int)(3.0 * (double)unnamed_idx_1);
  emxEnsureCapacity((emxArray__common *)x0, nm1d2, (int)sizeof(double));
  nm1d2 = (int)(3.0 * (double)unnamed_idx_1);
  for (unnamed_idx_1 = 0; unnamed_idx_1 < nm1d2; unnamed_idx_1++) {
    x0->data[unnamed_idx_1] = 0.0;
  }

  for (k = 0; k < i0; k++) {
    x0->data[(int)((1.0 + (double)k) * 3.0 - 2.0) - 1] = comPoints->data[k];
    x0->data[(int)((1.0 + (double)k) * 3.0 - 1.0) - 1] = comPoints->data[k +
      comPoints->size[0]];
  }

  emxFree_real_T(&comPoints);
  emxInit_real_T(&r0, 2);
  nm1d2 = x0->size[1];
  n = (int)(3.0 * (double)i0);
  unnamed_idx_1 = x0->size[0] * x0->size[1];
  x0->size[1] = nm1d2 + (int)(3.0 * (double)i0);
  emxEnsureCapacity((emxArray__common *)x0, unnamed_idx_1, (int)sizeof(double));
  unnamed_idx_1 = (int)(3.0 * (double)i0);
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
  for (i0 = 0; i0 < unnamed_idx_1; i0++) {
    r0->data[r0->size[0] * i0] = 0.0;
  }

  for (i0 = 0; i0 < n; i0++) {
    x0->data[nm1d2 + i0] = r0->data[i0];
  }

  emxFree_real_T(&r0);
  emxInit_real_T1(&ynew, 1);
  nx0 = (double)x0->size[1] / 2.0;

  /*   Reinier Kuppens 4252071 20-03-2014 */
  /*    */
  /*   Runge Kutta 4th order */
  b_flag = 1;
  b_t = 0.0;
  i0 = ynew->size[0];
  ynew->size[0] = x0->size[1];
  emxEnsureCapacity((emxArray__common *)ynew, i0, (int)sizeof(double));
  nm1d2 = x0->size[1];
  for (i0 = 0; i0 < nm1d2; i0++) {
    ynew->data[i0] = x0->data[i0];
  }

  if (rtIsNaN(h) || rtIsNaN(T)) {
    n = 1;
    anew = rtNaN;
    apnd = T;
  } else if ((h == 0.0) || ((0.0 < T) && (h < 0.0)) || ((T < 0.0) && (h > 0.0)))
  {
    n = 0;
    anew = 0.0;
    apnd = T;
  } else if (rtIsInf(T)) {
    n = 1;
    anew = rtNaN;
    apnd = T;
  } else if (rtIsInf(h)) {
    n = 1;
    anew = 0.0;
    apnd = T;
  } else {
    anew = 0.0;
    ndbl = floor(T / h + 0.5);
    apnd = ndbl * h;
    if (h > 0.0) {
      cdiff = apnd - T;
    } else {
      cdiff = T - apnd;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs(T)) {
      ndbl++;
      apnd = T;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * h;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&r1, 2);
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = n;
  emxEnsureCapacity((emxArray__common *)r1, i0, (int)sizeof(double));
  if (n > 0) {
    r1->data[0] = anew;
    if (n > 1) {
      r1->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 1; k < nm1d2; k++) {
        ndbl = (double)k * h;
        r1->data[k] = anew + ndbl;
        r1->data[(n - k) - 1] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n - 1) {
        r1->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        ndbl = (double)nm1d2 * h;
        r1->data[nm1d2] = anew + ndbl;
        r1->data[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }

  i0 = t->size[0];
  t->size[0] = r1->size[1];
  emxEnsureCapacity((emxArray__common *)t, i0, (int)sizeof(double));
  nm1d2 = r1->size[1];
  for (i0 = 0; i0 < nm1d2; i0++) {
    t->data[i0] = 0.0;
  }

  i0 = qss->size[0] * qss->size[1];
  qss->size[0] = r1->size[1];
  emxEnsureCapacity((emxArray__common *)qss, i0, (int)sizeof(double));
  nm1d2 = x0->size[1];
  i0 = qss->size[0] * qss->size[1];
  qss->size[1] = nm1d2;
  emxEnsureCapacity((emxArray__common *)qss, i0, (int)sizeof(double));
  nm1d2 = x0->size[1];
  nm1d2 *= r1->size[1];
  for (i0 = 0; i0 < nm1d2; i0++) {
    qss->data[i0] = 0.0;
  }

  emxInit_int32_T(&r2, 1);
  nm1d2 = x0->size[1];
  i0 = r2->size[0];
  r2->size[0] = nm1d2;
  emxEnsureCapacity((emxArray__common *)r2, i0, (int)sizeof(int));
  for (i0 = 0; i0 < nm1d2; i0++) {
    r2->data[i0] = i0;
  }

  emxInit_real_T1(&b_x0, 1);
  i0 = b_x0->size[0];
  b_x0->size[0] = x0->size[1];
  emxEnsureCapacity((emxArray__common *)b_x0, i0, (int)sizeof(double));
  nm1d2 = x0->size[1];
  for (i0 = 0; i0 < nm1d2; i0++) {
    b_x0->data[i0] = x0->data[x0->size[0] * i0];
  }

  unnamed_idx_1 = r2->size[0];
  for (i0 = 0; i0 < unnamed_idx_1; i0++) {
    qss->data[qss->size[0] * r2->data[i0]] = b_x0->data[i0];
  }

  emxFree_real_T(&b_x0);
  emxFree_int32_T(&r2);

  /*  Main loop  */
  k = 1;
  emxInit_real_T1(&s1, 1);
  emxInit_real_T1(&s2, 1);
  emxInit_real_T1(&s3, 1);
  emxInit_real_T1(&s4, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_boolean_T1(&r3, 1);
  emxInit_real_T1(&b_ynew, 1);
  emxInit_real_T1(&c_ynew, 1);
  emxInit_real_T1(&d_ynew, 1);
  emxInit_real_T1(&e_ynew, 1);
  guard1 = false;
  do {
    exitg1 = 0;
    nm1d2 = r1->size[1];
    if (k - 1 <= nm1d2 - 2) {
      /* Runge-Kutta 4th order function evaluations */
      i0 = e_ynew->size[0];
      e_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity((emxArray__common *)e_ynew, i0, (int)sizeof(double));
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        e_ynew->data[i0] = ynew->data[i0];
      }

      eom(b_t, e_ynew, nx0, DNA->incstr, DNA->edgelabel, DNA->Mpar, DNA->Hpar,
          DNA->Spar, DNA->Ppar, DNA->Pmpar, s1);
      ndbl = h / 2.0;
      i0 = d_ynew->size[0];
      d_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity((emxArray__common *)d_ynew, i0, (int)sizeof(double));
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        d_ynew->data[i0] = ynew->data[i0] + ndbl * s1->data[i0];
      }

      eom(b_t + h / 2.0, d_ynew, nx0, DNA->incstr, DNA->edgelabel, DNA->Mpar,
          DNA->Hpar, DNA->Spar, DNA->Ppar, DNA->Pmpar, s2);
      ndbl = h / 2.0;
      i0 = c_ynew->size[0];
      c_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity((emxArray__common *)c_ynew, i0, (int)sizeof(double));
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        c_ynew->data[i0] = ynew->data[i0] + ndbl * s2->data[i0];
      }

      eom(b_t + h / 2.0, c_ynew, nx0, DNA->incstr, DNA->edgelabel, DNA->Mpar,
          DNA->Hpar, DNA->Spar, DNA->Ppar, DNA->Pmpar, s3);
      i0 = b_ynew->size[0];
      b_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity((emxArray__common *)b_ynew, i0, (int)sizeof(double));
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        b_ynew->data[i0] = ynew->data[i0] + h * s3->data[i0];
      }

      eom(b_t + h, b_ynew, nx0, DNA->incstr, DNA->edgelabel, DNA->Mpar,
          DNA->Hpar, DNA->Spar, DNA->Ppar, DNA->Pmpar, s4);
      ndbl = h / 6.0;
      i0 = ynew->size[0];
      emxEnsureCapacity((emxArray__common *)ynew, i0, (int)sizeof(double));
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        ynew->data[i0] += ndbl * (((s1->data[i0] + 2.0 * s2->data[i0]) + 2.0 *
          s3->data[i0]) + s4->data[i0]);
      }

      tnew = b_t + h;

      /* Update variables */
      b_t = tnew;
      t->data[k] = tnew;
      nm1d2 = ynew->size[0];
      for (i0 = 0; i0 < nm1d2; i0++) {
        qss->data[k + qss->size[0] * i0] = ynew->data[i0];
      }

      nm1d2 = qss->size[1];
      i0 = x0->size[0] * x0->size[1];
      x0->size[0] = 1;
      x0->size[1] = nm1d2;
      emxEnsureCapacity((emxArray__common *)x0, i0, (int)sizeof(double));
      for (i0 = 0; i0 < nm1d2; i0++) {
        x0->data[x0->size[0] * i0] = qss->data[k + qss->size[0] * i0] -
          qss->data[(k + qss->size[0] * i0) - 1];
      }

      /* Check for NAN and for large derivatives */
      i0 = r3->size[0];
      r3->size[0] = qss->size[0] * qss->size[1];
      emxEnsureCapacity((emxArray__common *)r3, i0, (int)sizeof(boolean_T));
      nm1d2 = qss->size[0] * qss->size[1];
      for (i0 = 0; i0 < nm1d2; i0++) {
        r3->data[i0] = rtIsNaN(qss->data[i0]);
      }

      if (any(r3)) {
        guard1 = true;
        exitg1 = 1;
      } else {
        ndbl = (double)x0->size[1] / 2.0;
        if (1.0 > ndbl) {
          nm1d2 = 0;
        } else {
          nm1d2 = (int)ndbl;
        }

        i0 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nm1d2;
        emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(boolean_T));
        for (i0 = 0; i0 < nm1d2; i0++) {
          x->data[x->size[0] * i0] = (x0->data[i0] > 10.0);
        }

        y = false;
        nm1d2 = 1;
        exitg2 = false;
        while ((!exitg2) && (nm1d2 <= x->size[1])) {
          b0 = !x->data[nm1d2 - 1];
          if (!b0) {
            y = true;
            exitg2 = true;
          } else {
            nm1d2++;
          }
        }

        if (y) {
          guard1 = true;
          exitg1 = 1;
        } else {
          k++;
          guard1 = false;
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (guard1) {
    b_flag = 0;
  }

  emxFree_real_T(&e_ynew);
  emxFree_real_T(&d_ynew);
  emxFree_real_T(&c_ynew);
  emxFree_real_T(&b_ynew);
  emxFree_boolean_T(&r3);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r1);
  emxFree_real_T(&ynew);
  emxFree_real_T(&s4);
  emxFree_real_T(&s3);
  emxFree_real_T(&s2);
  emxFree_real_T(&s1);
  emxFree_real_T(&x0);

  /*  end */
  *flag = b_flag;
}

/*
 * File trailer for simulateDNA.c
 *
 * [EOF]
 */
