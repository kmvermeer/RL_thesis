/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: newton_raphson.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "newton_raphson.h"
#include "simulateDNA_emxutil.h"
#include "mrdivide.h"
#include "getDk.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : double t
 *                emxArray_real_T *qss
 *                double nx0
 *                const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                const emxArray_real_T *DNA_Mpar
 *                const emxArray_real_T *DNA_Hpar
 *                const emxArray_real_T *DNA_Spar
 *                const emxArray_real_T *DNA_Ppar
 *                const emxArray_real_T *DNA_Pmpar
 * Return Type  : void
 */
void newton_raphson(double t, emxArray_real_T *qss, double nx0, const
                    emxArray_real_T *DNA_incstr, const emxArray_real_T
                    *DNA_edgelabel, const emxArray_real_T *DNA_Mpar, const
                    emxArray_real_T *DNA_Hpar, const emxArray_real_T *DNA_Spar,
                    const emxArray_real_T *DNA_Ppar, const emxArray_real_T
                    *DNA_Pmpar)
{
  int ar;
  emxArray_real_T *q_new;
  int i16;
  double mtmp;
  int i17;
  emxArray_real_T *qd_new;
  int ixstart;
  emxArray_real_T *D;
  int iter;
  emxArray_real_T *invJ;
  emxArray_real_T *Dt;
  emxArray_real_T *Dk;
  emxArray_int32_T *r14;
  emxArray_real_T *varargin_2;
  emxArray_real_T *y;
  int exitg3;
  int n;
  boolean_T exitg4;
  emxArray_real_T *Dd;
  int k;
  unsigned int invJ_idx_0;
  int ib;
  int m;
  unsigned int unnamed_idx_1;
  emxArray_real_T *C;
  emxArray_real_T *b_C;
  int ic;
  emxArray_real_T *b_y;
  int c;
  int exitg1;
  int ia;
  boolean_T exitg2;
  if (1.0 > nx0) {
    ar = 0;
  } else {
    ar = (int)nx0;
  }

  emxInit_real_T1(&q_new, 1);
  i16 = q_new->size[0];
  q_new->size[0] = ar;
  emxEnsureCapacity((emxArray__common *)q_new, i16, (int)sizeof(double));
  for (i16 = 0; i16 < ar; i16++) {
    q_new->data[i16] = qss->data[i16];
  }

  mtmp = nx0 * 2.0;
  if (nx0 + 1.0 > mtmp) {
    i16 = 0;
    i17 = 0;
  } else {
    i16 = (int)(nx0 + 1.0) - 1;
    i17 = (int)mtmp;
  }

  emxInit_real_T1(&qd_new, 1);
  ixstart = qd_new->size[0];
  qd_new->size[0] = i17 - i16;
  emxEnsureCapacity((emxArray__common *)qd_new, ixstart, (int)sizeof(double));
  ar = i17 - i16;
  for (i17 = 0; i17 < ar; i17++) {
    qd_new->data[i17] = qss->data[i16 + i17];
  }

  emxInit_real_T1(&D, 1);
  iter = 0;

  /*  F = constraint(q_tilde); */
  getDk(t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
        DNA_Ppar, DNA_Pmpar, D);

  /* constraint vector */
  emxInit_real_T(&invJ, 2);
  emxInit_real_T1(&Dt, 1);
  emxInit_real_T(&Dk, 2);
  emxInit_int32_T1(&r14, 2);
  emxInit_real_T1(&varargin_2, 1);
  emxInit_real_T(&y, 2);
  do {
    exitg3 = 0;
    b_abs(D, varargin_2);
    ixstart = 1;
    n = varargin_2->size[0];
    mtmp = varargin_2->data[0];
    if (varargin_2->size[0] > 1) {
      if (rtIsNaN(varargin_2->data[0])) {
        ar = 2;
        exitg4 = false;
        while ((!exitg4) && (ar <= n)) {
          ixstart = ar;
          if (!rtIsNaN(varargin_2->data[ar - 1])) {
            mtmp = varargin_2->data[ar - 1];
            exitg4 = true;
          } else {
            ar++;
          }
        }
      }

      if (ixstart < varargin_2->size[0]) {
        while (ixstart + 1 <= n) {
          if (varargin_2->data[ixstart] > mtmp) {
            mtmp = varargin_2->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if ((mtmp > 1.0E-12) && (iter < 1000)) {
      /*      J = constraintd(q_tilde); */
      /*      F = constraint(q_tilde); */
      b_getDk(t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
              DNA_Ppar, DNA_Pmpar, D, Dk);

      /*      F = getDk(qss,DNA); */
      i16 = invJ->size[0] * invJ->size[1];
      invJ->size[0] = Dk->size[1];
      invJ->size[1] = Dk->size[0];
      emxEnsureCapacity((emxArray__common *)invJ, i16, (int)sizeof(double));
      ar = Dk->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        ib = Dk->size[1];
        for (i17 = 0; i17 < ib; i17++) {
          invJ->data[i17 + invJ->size[0] * i16] = Dk->data[i16 + Dk->size[0] *
            i17];
        }
      }

      if ((Dk->size[1] == 1) || (invJ->size[0] == 1)) {
        i16 = y->size[0] * y->size[1];
        y->size[0] = Dk->size[0];
        y->size[1] = invJ->size[1];
        emxEnsureCapacity((emxArray__common *)y, i16, (int)sizeof(double));
        ar = Dk->size[0];
        for (i16 = 0; i16 < ar; i16++) {
          ib = invJ->size[1];
          for (i17 = 0; i17 < ib; i17++) {
            y->data[i16 + y->size[0] * i17] = 0.0;
            n = Dk->size[1];
            for (ixstart = 0; ixstart < n; ixstart++) {
              y->data[i16 + y->size[0] * i17] += Dk->data[i16 + Dk->size[0] *
                ixstart] * invJ->data[ixstart + invJ->size[0] * i17];
            }
          }
        }
      } else {
        k = Dk->size[1];
        invJ_idx_0 = (unsigned int)Dk->size[0];
        unnamed_idx_1 = (unsigned int)invJ->size[1];
        i16 = y->size[0] * y->size[1];
        y->size[0] = (int)invJ_idx_0;
        y->size[1] = (int)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)y, i16, (int)sizeof(double));
        m = Dk->size[0];
        i16 = y->size[0] * y->size[1];
        emxEnsureCapacity((emxArray__common *)y, i16, (int)sizeof(double));
        ar = y->size[1];
        for (i16 = 0; i16 < ar; i16++) {
          ib = y->size[0];
          for (i17 = 0; i17 < ib; i17++) {
            y->data[i17 + y->size[0] * i16] = 0.0;
          }
        }

        if ((Dk->size[0] == 0) || (invJ->size[1] == 0)) {
        } else {
          c = Dk->size[0] * (invJ->size[1] - 1);
          ixstart = 0;
          while ((m > 0) && (ixstart <= c)) {
            i16 = ixstart + m;
            for (ic = ixstart; ic + 1 <= i16; ic++) {
              y->data[ic] = 0.0;
            }

            ixstart += m;
          }

          n = 0;
          ixstart = 0;
          while ((m > 0) && (ixstart <= c)) {
            ar = -1;
            i16 = n + k;
            for (ib = n; ib + 1 <= i16; ib++) {
              if (invJ->data[ib] != 0.0) {
                ia = ar;
                i17 = ixstart + m;
                for (ic = ixstart; ic + 1 <= i17; ic++) {
                  ia++;
                  y->data[ic] += invJ->data[ib] * Dk->data[ia];
                }
              }

              ar += m;
            }

            n += k;
            ixstart += m;
          }
        }
      }

      i16 = invJ->size[0] * invJ->size[1];
      invJ->size[0] = Dk->size[1];
      invJ->size[1] = Dk->size[0];
      emxEnsureCapacity((emxArray__common *)invJ, i16, (int)sizeof(double));
      ar = Dk->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        ib = Dk->size[1];
        for (i17 = 0; i17 < ib; i17++) {
          invJ->data[i17 + invJ->size[0] * i16] = Dk->data[i16 + Dk->size[0] *
            i17];
        }
      }

      mrdivide(invJ, y);
      if ((invJ->size[1] == 1) || (D->size[0] == 1)) {
        i16 = Dt->size[0];
        Dt->size[0] = invJ->size[0];
        emxEnsureCapacity((emxArray__common *)Dt, i16, (int)sizeof(double));
        ar = invJ->size[0];
        for (i16 = 0; i16 < ar; i16++) {
          Dt->data[i16] = 0.0;
          ib = invJ->size[1];
          for (i17 = 0; i17 < ib; i17++) {
            Dt->data[i16] += invJ->data[i16 + invJ->size[0] * i17] * D->data[i17];
          }
        }
      } else {
        k = invJ->size[1];
        invJ_idx_0 = (unsigned int)invJ->size[0];
        i16 = Dt->size[0];
        Dt->size[0] = (int)invJ_idx_0;
        emxEnsureCapacity((emxArray__common *)Dt, i16, (int)sizeof(double));
        m = invJ->size[0];
        ixstart = Dt->size[0];
        i16 = Dt->size[0];
        Dt->size[0] = ixstart;
        emxEnsureCapacity((emxArray__common *)Dt, i16, (int)sizeof(double));
        for (i16 = 0; i16 < ixstart; i16++) {
          Dt->data[i16] = 0.0;
        }

        if (invJ->size[0] == 0) {
        } else {
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            for (ic = 1; ic <= m; ic++) {
              Dt->data[ic - 1] = 0.0;
            }

            ixstart = m;
          }

          n = 0;
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            ar = -1;
            i16 = n + k;
            for (ib = n; ib + 1 <= i16; ib++) {
              if (D->data[ib] != 0.0) {
                ia = ar;
                for (ic = 0; ic + 1 <= m; ic++) {
                  ia++;
                  Dt->data[ic] += D->data[ib] * invJ->data[ia];
                }
              }

              ar += m;
            }

            n += k;
            ixstart = m;
          }
        }
      }

      i16 = q_new->size[0];
      emxEnsureCapacity((emxArray__common *)q_new, i16, (int)sizeof(double));
      ar = q_new->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        q_new->data[i16] -= Dt->data[i16];
      }

      iter++;
      if (1.0 > nx0) {
        ar = 0;
      } else {
        ar = (int)nx0;
      }

      i16 = r14->size[0] * r14->size[1];
      r14->size[0] = 1;
      r14->size[1] = ar;
      emxEnsureCapacity((emxArray__common *)r14, i16, (int)sizeof(int));
      for (i16 = 0; i16 < ar; i16++) {
        r14->data[r14->size[0] * i16] = i16;
      }

      ar = r14->size[1];
      for (i16 = 0; i16 < ar; i16++) {
        qss->data[r14->data[r14->size[0] * i16]] = q_new->data[(*(int (*)[2])
          r14->size)[0] * i16];
      }
    } else {
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  emxFree_real_T(&y);
  emxFree_real_T(&q_new);

  /*  F = constraintd(qss)*qd_tilde; */
  c_getDk(t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
          DNA_Ppar, DNA_Pmpar, D, invJ, varargin_2, Dt);
  emxInit_real_T1(&Dd, 1);
  if ((invJ->size[1] == 1) || (qd_new->size[0] == 1)) {
    i16 = Dd->size[0];
    Dd->size[0] = invJ->size[0];
    emxEnsureCapacity((emxArray__common *)Dd, i16, (int)sizeof(double));
    ar = invJ->size[0];
    for (i16 = 0; i16 < ar; i16++) {
      Dd->data[i16] = 0.0;
      ib = invJ->size[1];
      for (i17 = 0; i17 < ib; i17++) {
        Dd->data[i16] += invJ->data[i16 + invJ->size[0] * i17] * qd_new->
          data[i17];
      }
    }
  } else {
    k = invJ->size[1];
    invJ_idx_0 = (unsigned int)invJ->size[0];
    i16 = Dd->size[0];
    Dd->size[0] = (int)invJ_idx_0;
    emxEnsureCapacity((emxArray__common *)Dd, i16, (int)sizeof(double));
    m = invJ->size[0];
    ixstart = Dd->size[0];
    i16 = Dd->size[0];
    Dd->size[0] = ixstart;
    emxEnsureCapacity((emxArray__common *)Dd, i16, (int)sizeof(double));
    for (i16 = 0; i16 < ixstart; i16++) {
      Dd->data[i16] = 0.0;
    }

    if (invJ->size[0] == 0) {
    } else {
      ixstart = 0;
      while ((m > 0) && (ixstart <= 0)) {
        for (ic = 1; ic <= m; ic++) {
          Dd->data[ic - 1] = 0.0;
        }

        ixstart = m;
      }

      n = 0;
      ixstart = 0;
      while ((m > 0) && (ixstart <= 0)) {
        ar = -1;
        i16 = n + k;
        for (ib = n; ib + 1 <= i16; ib++) {
          if (qd_new->data[ib] != 0.0) {
            ia = ar;
            for (ic = 0; ic + 1 <= m; ic++) {
              ia++;
              Dd->data[ic] += qd_new->data[ib] * invJ->data[ia];
            }
          }

          ar += m;
        }

        n += k;
        ixstart = m;
      }
    }
  }

  i16 = Dd->size[0];
  emxEnsureCapacity((emxArray__common *)Dd, i16, (int)sizeof(double));
  ar = Dd->size[0];
  for (i16 = 0; i16 < ar; i16++) {
    Dd->data[i16] += Dt->data[i16];
  }

  emxFree_real_T(&Dt);
  iter = 0;
  emxInit_real_T1(&C, 1);
  emxInit_real_T1(&b_C, 1);
  emxInit_real_T(&b_y, 2);
  do {
    exitg1 = 0;
    b_abs(Dd, varargin_2);
    ixstart = 1;
    n = varargin_2->size[0];
    mtmp = varargin_2->data[0];
    if (varargin_2->size[0] > 1) {
      if (rtIsNaN(varargin_2->data[0])) {
        ar = 2;
        exitg2 = false;
        while ((!exitg2) && (ar <= n)) {
          ixstart = ar;
          if (!rtIsNaN(varargin_2->data[ar - 1])) {
            mtmp = varargin_2->data[ar - 1];
            exitg2 = true;
          } else {
            ar++;
          }
        }
      }

      if (ixstart < varargin_2->size[0]) {
        while (ixstart + 1 <= n) {
          if (varargin_2->data[ixstart] > mtmp) {
            mtmp = varargin_2->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if ((mtmp > 1.0E-12) && (iter < 1000)) {
      /*      J   = constraintd(qss(1:nx0)); */
      c_getDk(t, qss, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
              DNA_Ppar, DNA_Pmpar, D, Dk, varargin_2, Dd);
      if ((Dk->size[1] == 1) || (qd_new->size[0] == 1)) {
        i16 = C->size[0];
        C->size[0] = Dk->size[0];
        emxEnsureCapacity((emxArray__common *)C, i16, (int)sizeof(double));
        ar = Dk->size[0];
        for (i16 = 0; i16 < ar; i16++) {
          C->data[i16] = 0.0;
          ib = Dk->size[1];
          for (i17 = 0; i17 < ib; i17++) {
            C->data[i16] += Dk->data[i16 + Dk->size[0] * i17] * qd_new->data[i17];
          }
        }
      } else {
        k = Dk->size[1];
        invJ_idx_0 = (unsigned int)Dk->size[0];
        i16 = C->size[0];
        C->size[0] = (int)invJ_idx_0;
        emxEnsureCapacity((emxArray__common *)C, i16, (int)sizeof(double));
        m = Dk->size[0];
        ixstart = C->size[0];
        i16 = C->size[0];
        C->size[0] = ixstart;
        emxEnsureCapacity((emxArray__common *)C, i16, (int)sizeof(double));
        for (i16 = 0; i16 < ixstart; i16++) {
          C->data[i16] = 0.0;
        }

        if (Dk->size[0] == 0) {
        } else {
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            for (ic = 1; ic <= m; ic++) {
              C->data[ic - 1] = 0.0;
            }

            ixstart = m;
          }

          n = 0;
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            ar = -1;
            i16 = n + k;
            for (ib = n; ib + 1 <= i16; ib++) {
              if (qd_new->data[ib] != 0.0) {
                ia = ar;
                for (ic = 0; ic + 1 <= m; ic++) {
                  ia++;
                  C->data[ic] += qd_new->data[ib] * Dk->data[ia];
                }
              }

              ar += m;
            }

            n += k;
            ixstart = m;
          }
        }
      }

      i16 = Dd->size[0];
      Dd->size[0] = C->size[0];
      emxEnsureCapacity((emxArray__common *)Dd, i16, (int)sizeof(double));
      ar = C->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        Dd->data[i16] += C->data[i16];
      }

      i16 = invJ->size[0] * invJ->size[1];
      invJ->size[0] = Dk->size[1];
      invJ->size[1] = Dk->size[0];
      emxEnsureCapacity((emxArray__common *)invJ, i16, (int)sizeof(double));
      ar = Dk->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        ib = Dk->size[1];
        for (i17 = 0; i17 < ib; i17++) {
          invJ->data[i17 + invJ->size[0] * i16] = Dk->data[i16 + Dk->size[0] *
            i17];
        }
      }

      if ((Dk->size[1] == 1) || (invJ->size[0] == 1)) {
        i16 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = Dk->size[0];
        b_y->size[1] = invJ->size[1];
        emxEnsureCapacity((emxArray__common *)b_y, i16, (int)sizeof(double));
        ar = Dk->size[0];
        for (i16 = 0; i16 < ar; i16++) {
          ib = invJ->size[1];
          for (i17 = 0; i17 < ib; i17++) {
            b_y->data[i16 + b_y->size[0] * i17] = 0.0;
            n = Dk->size[1];
            for (ixstart = 0; ixstart < n; ixstart++) {
              b_y->data[i16 + b_y->size[0] * i17] += Dk->data[i16 + Dk->size[0] *
                ixstart] * invJ->data[ixstart + invJ->size[0] * i17];
            }
          }
        }
      } else {
        k = Dk->size[1];
        invJ_idx_0 = (unsigned int)Dk->size[0];
        unnamed_idx_1 = (unsigned int)invJ->size[1];
        i16 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = (int)invJ_idx_0;
        b_y->size[1] = (int)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)b_y, i16, (int)sizeof(double));
        m = Dk->size[0];
        i16 = b_y->size[0] * b_y->size[1];
        emxEnsureCapacity((emxArray__common *)b_y, i16, (int)sizeof(double));
        ar = b_y->size[1];
        for (i16 = 0; i16 < ar; i16++) {
          ib = b_y->size[0];
          for (i17 = 0; i17 < ib; i17++) {
            b_y->data[i17 + b_y->size[0] * i16] = 0.0;
          }
        }

        if ((Dk->size[0] == 0) || (invJ->size[1] == 0)) {
        } else {
          c = Dk->size[0] * (invJ->size[1] - 1);
          ixstart = 0;
          while ((m > 0) && (ixstart <= c)) {
            i16 = ixstart + m;
            for (ic = ixstart; ic + 1 <= i16; ic++) {
              b_y->data[ic] = 0.0;
            }

            ixstart += m;
          }

          n = 0;
          ixstart = 0;
          while ((m > 0) && (ixstart <= c)) {
            ar = -1;
            i16 = n + k;
            for (ib = n; ib + 1 <= i16; ib++) {
              if (invJ->data[ib] != 0.0) {
                ia = ar;
                i17 = ixstart + m;
                for (ic = ixstart; ic + 1 <= i17; ic++) {
                  ia++;
                  b_y->data[ic] += invJ->data[ib] * Dk->data[ia];
                }
              }

              ar += m;
            }

            n += k;
            ixstart += m;
          }
        }
      }

      i16 = invJ->size[0] * invJ->size[1];
      invJ->size[0] = Dk->size[1];
      invJ->size[1] = Dk->size[0];
      emxEnsureCapacity((emxArray__common *)invJ, i16, (int)sizeof(double));
      ar = Dk->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        ib = Dk->size[1];
        for (i17 = 0; i17 < ib; i17++) {
          invJ->data[i17 + invJ->size[0] * i16] = Dk->data[i16 + Dk->size[0] *
            i17];
        }
      }

      mrdivide(invJ, b_y);
      if ((invJ->size[1] == 1) || (Dd->size[0] == 1)) {
        i16 = b_C->size[0];
        b_C->size[0] = invJ->size[0];
        emxEnsureCapacity((emxArray__common *)b_C, i16, (int)sizeof(double));
        ar = invJ->size[0];
        for (i16 = 0; i16 < ar; i16++) {
          b_C->data[i16] = 0.0;
          ib = invJ->size[1];
          for (i17 = 0; i17 < ib; i17++) {
            b_C->data[i16] += invJ->data[i16 + invJ->size[0] * i17] * Dd->
              data[i17];
          }
        }
      } else {
        k = invJ->size[1];
        invJ_idx_0 = (unsigned int)invJ->size[0];
        i16 = b_C->size[0];
        b_C->size[0] = (int)invJ_idx_0;
        emxEnsureCapacity((emxArray__common *)b_C, i16, (int)sizeof(double));
        m = invJ->size[0];
        ixstart = b_C->size[0];
        i16 = b_C->size[0];
        b_C->size[0] = ixstart;
        emxEnsureCapacity((emxArray__common *)b_C, i16, (int)sizeof(double));
        for (i16 = 0; i16 < ixstart; i16++) {
          b_C->data[i16] = 0.0;
        }

        if (invJ->size[0] == 0) {
        } else {
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            for (ic = 1; ic <= m; ic++) {
              b_C->data[ic - 1] = 0.0;
            }

            ixstart = m;
          }

          n = 0;
          ixstart = 0;
          while ((m > 0) && (ixstart <= 0)) {
            ar = -1;
            i16 = n + k;
            for (ib = n; ib + 1 <= i16; ib++) {
              if (Dd->data[ib] != 0.0) {
                ia = ar;
                for (ic = 0; ic + 1 <= m; ic++) {
                  ia++;
                  b_C->data[ic] += Dd->data[ib] * invJ->data[ia];
                }
              }

              ar += m;
            }

            n += k;
            ixstart = m;
          }
        }
      }

      i16 = qd_new->size[0];
      emxEnsureCapacity((emxArray__common *)qd_new, i16, (int)sizeof(double));
      ar = qd_new->size[0];
      for (i16 = 0; i16 < ar; i16++) {
        qd_new->data[i16] -= b_C->data[i16];
      }

      iter++;
      mtmp = nx0 * 2.0;
      if (nx0 + 1.0 > mtmp) {
        i16 = 0;
        i17 = 0;
      } else {
        i16 = (int)(nx0 + 1.0) - 1;
        i17 = (int)mtmp;
      }

      ixstart = r14->size[0] * r14->size[1];
      r14->size[0] = 1;
      r14->size[1] = i17 - i16;
      emxEnsureCapacity((emxArray__common *)r14, ixstart, (int)sizeof(int));
      ar = i17 - i16;
      for (i17 = 0; i17 < ar; i17++) {
        r14->data[r14->size[0] * i17] = i16 + i17;
      }

      ar = r14->size[1];
      for (i16 = 0; i16 < ar; i16++) {
        qss->data[r14->data[r14->size[0] * i16]] = qd_new->data[(*(int (*)[2])
          r14->size)[0] * i16];
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_y);
  emxFree_real_T(&varargin_2);
  emxFree_int32_T(&r14);
  emxFree_real_T(&b_C);
  emxFree_real_T(&C);
  emxFree_real_T(&Dk);
  emxFree_real_T(&qd_new);
  emxFree_real_T(&Dd);
  emxFree_real_T(&invJ);
  emxFree_real_T(&D);
}

/*
 * File trailer for newton_raphson.c
 *
 * [EOF]
 */
