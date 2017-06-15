/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getCompoints.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getCompoints.h"
#include "sum.h"
#include "simulateDNA_emxutil.h"
#include "mean.h"
#include "DNA2inc.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                const emxArray_real_T *DNA_Mpar
 *                const emxArray_real_T *DNA_Hpar
 *                const emxArray_real_T *DNA_Spar
 *                const emxArray_real_T *DNA_Ppar
 *                const emxArray_real_T *DNA_Pmpar
 *                emxArray_real_T *comPoint
 * Return Type  : void
 */
void getCompoints(const emxArray_real_T *DNA_incstr, const emxArray_real_T
                  *DNA_edgelabel, const emxArray_real_T *DNA_Mpar, const
                  emxArray_real_T *DNA_Hpar, const emxArray_real_T *DNA_Spar,
                  const emxArray_real_T *DNA_Ppar, const emxArray_real_T
                  *DNA_Pmpar, emxArray_real_T *comPoint)
{
  int i1;
  int i2;
  int nx;
  int loop_ub;
  emxArray_real_T *inc;
  int k;
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
  int idx;
  int c_ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  double b_points[4];
  double y[2];
  double b_edgelabel;
  boolean_T x_data[100];
  int ii_data[100];
  double Hidx;
  double Pmidx;
  double Sidx;
  boolean_T exitg1;
  double Pidx;
  boolean_T guard1 = false;
  int i_data[100];
  boolean_T exitg2;
  boolean_T guard2 = false;
  i1 = DNA_Mpar->size[0];

  /* Number of masses */
  i2 = DNA_Mpar->size[0];
  nx = comPoint->size[0] * comPoint->size[1];
  comPoint->size[0] = i2 - 1;
  comPoint->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)comPoint, nx, (int)sizeof(double));
  loop_ub = (i2 - 1) << 1;
  for (i2 = 0; i2 < loop_ub; i2++) {
    comPoint->data[i2] = 0.0;
  }

  emxInit_real_T(&inc, 2);

  /* Initialize compoint array */
  DNA2inc(DNA_incstr, inc);
  k = 0;
  emxInit_real_T(&edgeIdx, 2);
  emxInit_real_T(&edgelabel, 2);
  emxInit_real_T(&points, 2);
  emxInit_real_T1(&vrtxIdx, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T1(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&b_ii, 1);
  emxInit_boolean_T(&b_DNA_edgelabel, 2);
  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  emxInit_boolean_T(&d_DNA_edgelabel, 2);
  emxInit_boolean_T(&e_DNA_edgelabel, 2);
  emxInit_boolean_T(&f_DNA_edgelabel, 2);
  emxInit_boolean_T(&g_DNA_edgelabel, 2);
  emxInit_boolean_T(&h_DNA_edgelabel, 2);
  emxInit_boolean_T(&i_DNA_edgelabel, 2);
  while (k <= i1 - 2) {
    /* for all masses */
    loop_ub = inc->size[1];
    i2 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)x, i2, (int)sizeof(boolean_T));
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[x->size[0] * i2] = (inc->data[(k + inc->size[0] * i2) + 1] == 1.0);
    }

    nx = x->size[1];
    idx = 0;
    i2 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)ii, i2, (int)sizeof(int));
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

    if (x->size[1] == 1) {
      if (idx == 0) {
        i2 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)ii, i2, (int)sizeof(int));
      }
    } else {
      i2 = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      emxEnsureCapacity((emxArray__common *)ii, i2, (int)sizeof(int));
    }

    i2 = edgeIdx->size[0] * edgeIdx->size[1];
    edgeIdx->size[0] = 1;
    edgeIdx->size[1] = ii->size[1];
    emxEnsureCapacity((emxArray__common *)edgeIdx, i2, (int)sizeof(double));
    loop_ub = ii->size[0] * ii->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      edgeIdx->data[i2] = ii->data[i2];
    }

    /* verbonden edges per mass */
    i2 = edgelabel->size[0] * edgelabel->size[1];
    edgelabel->size[0] = 1;
    edgelabel->size[1] = edgeIdx->size[1];
    emxEnsureCapacity((emxArray__common *)edgelabel, i2, (int)sizeof(double));
    loop_ub = edgeIdx->size[0] * edgeIdx->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      edgelabel->data[i2] = DNA_edgelabel->data[(int)edgeIdx->data[i2] - 1];
    }

    if (edgeIdx->size[1] == 1) {
      /* If there is only one edge */
      for (i2 = 0; i2 < 4; i2++) {
        b_points[i2] = 0.0;
      }

      /* Empty point array  */
      for (i2 = 0; i2 < 2; i2++) {
        b_points[i2 << 1] = DNA_Mpar->data[(k + DNA_Mpar->size[0] * i2) + 1];
      }

      /* Get first point out of mass data */
      if (DNA_edgelabel->data[(int)edgeIdx->data[0] - 1] == 1.0) {
        /* for hinge               %If connection is hinge */
        loop_ub = (int)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int)edgeIdx->data[0] - 1];
        i2 = i_DNA_edgelabel->size[0] * i_DNA_edgelabel->size[1];
        i_DNA_edgelabel->size[0] = 1;
        i_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity((emxArray__common *)i_DNA_edgelabel, i2, (int)sizeof
                          (boolean_T));
        for (i2 = 0; i2 < loop_ub; i2++) {
          i_DNA_edgelabel->data[i_DNA_edgelabel->size[0] * i2] =
            (DNA_edgelabel->data[i2] == b_edgelabel);
        }

        Hidx = sum(i_DNA_edgelabel);
        for (i2 = 0; i2 < 2; i2++) {
          b_points[1 + (i2 << 1)] = DNA_Hpar->data[i2 + DNA_Hpar->size[0] *
            ((int)Hidx - 1)];
        }
      } else if (DNA_edgelabel->data[(int)edgeIdx->data[0] - 1] == 2.0) {
        /* for spring */
        loop_ub = (int)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int)edgeIdx->data[0] - 1];
        i2 = h_DNA_edgelabel->size[0] * h_DNA_edgelabel->size[1];
        h_DNA_edgelabel->size[0] = 1;
        h_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity((emxArray__common *)h_DNA_edgelabel, i2, (int)sizeof
                          (boolean_T));
        for (i2 = 0; i2 < loop_ub; i2++) {
          h_DNA_edgelabel->data[h_DNA_edgelabel->size[0] * i2] =
            (DNA_edgelabel->data[i2] == b_edgelabel);
        }

        Sidx = sum(h_DNA_edgelabel);
        loop_ub = inc->size[0];
        i2 = b_x->size[0] * b_x->size[1];
        b_x->size[0] = loop_ub;
        b_x->size[1] = edgeIdx->size[1];
        emxEnsureCapacity((emxArray__common *)b_x, i2, (int)sizeof(boolean_T));
        idx = edgeIdx->size[1];
        for (i2 = 0; i2 < idx; i2++) {
          for (nx = 0; nx < loop_ub; nx++) {
            b_x->data[nx + b_x->size[0] * i2] = (inc->data[nx + inc->size[0] *
              ((int)edgeIdx->data[edgeIdx->size[0] * i2] - 1)] == 1.0);
          }
        }

        nx = b_x->size[0];
        idx = 0;
        i2 = b_ii->size[0];
        b_ii->size[0] = nx;
        emxEnsureCapacity((emxArray__common *)b_ii, i2, (int)sizeof(int));
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

        if (nx == 1) {
          if (idx == 0) {
            i2 = b_ii->size[0];
            b_ii->size[0] = 0;
            emxEnsureCapacity((emxArray__common *)b_ii, i2, (int)sizeof(int));
          }
        } else {
          i2 = b_ii->size[0];
          if (1 > idx) {
            b_ii->size[0] = 0;
          } else {
            b_ii->size[0] = idx;
          }

          emxEnsureCapacity((emxArray__common *)b_ii, i2, (int)sizeof(int));
        }

        i2 = vrtxIdx->size[0];
        vrtxIdx->size[0] = b_ii->size[0];
        emxEnsureCapacity((emxArray__common *)vrtxIdx, i2, (int)sizeof(double));
        loop_ub = b_ii->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          vrtxIdx->data[i2] = b_ii->data[i2];
        }

        if (1.0 + (double)k == vrtxIdx->data[0] - 1.0) {
          for (i2 = 0; i2 < 2; i2++) {
            b_points[1 + (i2 << 1)] = DNA_Spar->data[i2 + DNA_Spar->size[0] *
              ((int)Sidx - 1)];
          }
        } else {
          if (1.0 + (double)k == vrtxIdx->data[1] - 1.0) {
            for (i2 = 0; i2 < 2; i2++) {
              b_points[1 + (i2 << 1)] = DNA_Spar->data[(i2 + DNA_Spar->size[0] *
                ((int)Sidx - 1)) + 2];
            }
          }
        }
      } else if (DNA_edgelabel->data[(int)edgeIdx->data[0] - 1] == 3.0) {
        /* for prismatic joint */
        loop_ub = (int)edgeIdx->data[0];
        b_edgelabel = DNA_edgelabel->data[(int)edgeIdx->data[0] - 1];
        i2 = g_DNA_edgelabel->size[0] * g_DNA_edgelabel->size[1];
        g_DNA_edgelabel->size[0] = 1;
        g_DNA_edgelabel->size[1] = loop_ub;
        emxEnsureCapacity((emxArray__common *)g_DNA_edgelabel, i2, (int)sizeof
                          (boolean_T));
        for (i2 = 0; i2 < loop_ub; i2++) {
          g_DNA_edgelabel->data[g_DNA_edgelabel->size[0] * i2] =
            (DNA_edgelabel->data[i2] == b_edgelabel);
        }

        Pidx = sum(g_DNA_edgelabel);
        for (i2 = 0; i2 < 2; i2++) {
          b_points[1 + (i2 << 1)] = DNA_Ppar->data[i2 + DNA_Ppar->size[0] *
            ((int)Pidx - 1)];
        }
      } else {
        if (DNA_edgelabel->data[(int)edgeIdx->data[0] - 1] == 4.0) {
          loop_ub = (int)edgeIdx->data[0];
          i2 = f_DNA_edgelabel->size[0] * f_DNA_edgelabel->size[1];
          f_DNA_edgelabel->size[0] = 1;
          f_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity((emxArray__common *)f_DNA_edgelabel, i2, (int)sizeof
                            (boolean_T));
          for (i2 = 0; i2 < loop_ub; i2++) {
            f_DNA_edgelabel->data[f_DNA_edgelabel->size[0] * i2] =
              (DNA_edgelabel->data[i2] == edgelabel->data[edgelabel->size[0] *
               i2]);
          }

          Pmidx = sum(f_DNA_edgelabel);
          for (i2 = 0; i2 < 2; i2++) {
            b_points[1 + (i2 << 1)] = DNA_Pmpar->data[i2 + DNA_Pmpar->size[0] *
              ((int)Pmidx - 1)];
          }
        }
      }

      for (nx = 0; nx < 2; nx++) {
        y[nx] = b_points[nx << 1] + b_points[(nx << 1) + 1];
      }

      for (i2 = 0; i2 < 2; i2++) {
        comPoint->data[k + comPoint->size[0] * i2] = y[i2] / 2.0;
      }
    } else {
      /* If there is more than one edge */
      i2 = points->size[0] * points->size[1];
      points->size[0] = edgeIdx->size[1];
      points->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)points, i2, (int)sizeof(double));
      loop_ub = edgeIdx->size[1] << 1;
      for (i2 = 0; i2 < loop_ub; i2++) {
        points->data[i2] = 0.0;
      }

      for (c_ii = 0; c_ii < edgeIdx->size[1]; c_ii++) {
        if (edgelabel->data[c_ii] == 1.0) {
          /* For hinge */
          loop_ub = (int)edgeIdx->data[c_ii];
          b_edgelabel = edgelabel->data[c_ii];
          i2 = e_DNA_edgelabel->size[0] * e_DNA_edgelabel->size[1];
          e_DNA_edgelabel->size[0] = 1;
          e_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity((emxArray__common *)e_DNA_edgelabel, i2, (int)sizeof
                            (boolean_T));
          for (i2 = 0; i2 < loop_ub; i2++) {
            e_DNA_edgelabel->data[e_DNA_edgelabel->size[0] * i2] =
              (DNA_edgelabel->data[i2] == b_edgelabel);
          }

          Hidx = sum(e_DNA_edgelabel);
          for (i2 = 0; i2 < 2; i2++) {
            points->data[c_ii + points->size[0] * i2] = DNA_Hpar->data[i2 +
              DNA_Hpar->size[0] * ((int)Hidx - 1)];
          }
        } else if (edgelabel->data[c_ii] == 2.0) {
          /* For spring */
          loop_ub = inc->size[0];
          nx = (int)edgeIdx->data[c_ii];
          for (i2 = 0; i2 < loop_ub; i2++) {
            x_data[i2] = (inc->data[i2 + inc->size[0] * (nx - 1)] == 1.0);
          }

          idx = 0;
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

          if (loop_ub == 1) {
            if (idx == 0) {
              loop_ub = 0;
            }
          } else if (1 > idx) {
            loop_ub = 0;
          } else {
            loop_ub = idx;
          }

          for (i2 = 0; i2 < loop_ub; i2++) {
            i_data[i2] = ii_data[i2];
          }

          loop_ub = (int)edgeIdx->data[c_ii];
          b_edgelabel = edgelabel->data[c_ii];
          i2 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
          d_DNA_edgelabel->size[0] = 1;
          d_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity((emxArray__common *)d_DNA_edgelabel, i2, (int)sizeof
                            (boolean_T));
          for (i2 = 0; i2 < loop_ub; i2++) {
            d_DNA_edgelabel->data[d_DNA_edgelabel->size[0] * i2] =
              (DNA_edgelabel->data[i2] == b_edgelabel);
          }

          Sidx = sum(d_DNA_edgelabel);
          if (1.0 + (double)k == (double)i_data[0] - 1.0) {
            for (i2 = 0; i2 < 2; i2++) {
              points->data[c_ii + points->size[0] * i2] = DNA_Spar->data[i2 +
                DNA_Spar->size[0] * ((int)Sidx - 1)];
            }
          } else {
            if (1.0 + (double)k == (double)i_data[1] - 1.0) {
              for (i2 = 0; i2 < 2; i2++) {
                points->data[c_ii + points->size[0] * i2] = DNA_Spar->data[(i2 +
                  DNA_Spar->size[0] * ((int)Sidx - 1)) + 2];
              }
            }
          }
        } else if (edgelabel->data[c_ii] == 3.0) {
          /* For prismatic joint */
          loop_ub = (int)edgeIdx->data[c_ii];
          b_edgelabel = edgelabel->data[c_ii];
          i2 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
          c_DNA_edgelabel->size[0] = 1;
          c_DNA_edgelabel->size[1] = loop_ub;
          emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, i2, (int)sizeof
                            (boolean_T));
          for (i2 = 0; i2 < loop_ub; i2++) {
            c_DNA_edgelabel->data[c_DNA_edgelabel->size[0] * i2] =
              (DNA_edgelabel->data[i2] == b_edgelabel);
          }

          Pidx = sum(c_DNA_edgelabel);
          for (i2 = 0; i2 < 2; i2++) {
            points->data[c_ii + points->size[0] * i2] = DNA_Ppar->data[i2 +
              DNA_Ppar->size[0] * ((int)Pidx - 1)];
          }
        } else {
          if (edgelabel->data[c_ii] == 4.0) {
            loop_ub = (int)edgeIdx->data[c_ii];
            b_edgelabel = edgelabel->data[c_ii];
            i2 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
            b_DNA_edgelabel->size[0] = 1;
            b_DNA_edgelabel->size[1] = loop_ub;
            emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, i2, (int)
                              sizeof(boolean_T));
            for (i2 = 0; i2 < loop_ub; i2++) {
              b_DNA_edgelabel->data[b_DNA_edgelabel->size[0] * i2] =
                (DNA_edgelabel->data[i2] == b_edgelabel);
            }

            Pmidx = sum(b_DNA_edgelabel);
            for (i2 = 0; i2 < 2; i2++) {
              points->data[c_ii + points->size[0] * i2] = DNA_Pmpar->data[i2 +
                DNA_Pmpar->size[0] * ((int)Pmidx - 1)];
            }
          }
        }
      }

      mean(points, y);
      for (i2 = 0; i2 < 2; i2++) {
        comPoint->data[k + comPoint->size[0] * i2] = y[i2];
      }
    }

    k++;
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
}

/*
 * File trailer for getCompoints.c
 *
 * [EOF]
 */
