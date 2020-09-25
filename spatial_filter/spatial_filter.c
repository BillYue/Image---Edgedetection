// Applies a spatial filter of M*N to the target image

#include "mex.h"
#include "matrix.h"

void filter (int imgsize[], int filtersize[], const double *imgptr, const double *filmsk, double *output)
{
    int N_f = filtersize[0], M_f = filtersize[1];
    int N_i = imgsize[0], M_i = imgsize[1];
    int index, filindex, i, j, x, y, temp;
   // int deriv = 0;
    double product, sum = 0.0, weight = 0.0;
    double iM_img[N_i][M_i], filter[N_f][M_f];
    // check if derivative kernel
  //  for (i = 0; i < (N_f * M_f); i++)
    //    sum += filmsk[i];
   // if (sum == 0.0)
   //     deriv = 1;
   // else
   //     sum = 0.0;
    // fill the output array from the imgptr if a blurring filter
    // (all but the border will be replaced)
    for (i = 0; i < M_i; i++)
    {
        for (j = 0; j < N_i; j++)
        {
            index = i*N_i + j;
            //if (deriv == 0)
                output[index] = imgptr[index];
            iM_img[j][i] = imgptr[index];
            
        }
    }
    
    for (i = M_f/2; i < (M_i - M_f/2); i++)
    {
        for (j = N_f/2; j < (N_i - N_f/2); j++)
        {
               for (x = 0; x < M_f; x++)
                {
                    for (y = 0; y < N_f; y++)
                    {
                        filindex = x + (N_f*y);
                        product = iM_img[j - M_f/2 + y][i - N_f/2 + x] * filmsk[filindex]; 
                        sum += product;
                    }
                }
                
                index = i*N_i + j;
                output[index] = sum;
                
                sum = 0.0;
                product = 0.0;
                
        }
    }
    
}

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int i, imgsize[2], filtersize[2];
	int arraysize = 2;
    double *imgptr, *filterptr, *output;
    
    
    if (nrhs != 2)
        mexErrMsgTxt("Error:  two imgptr arguements required.");
  
    
  
    const mwSize *imgsizes = mxGetDimensions(prhs[0]);
    const mwSize *filterdims = mxGetDimensions(prhs[1]);
    
  
    for (i = 0; i <2; i++)
    {
        imgsize[i] = imgsizes[i];
        filtersize[i] = filterdims[i];
    }
    imgptr = mxGetPr(prhs[0]);
    filterptr = mxGetPr(prhs[1]);
    
	mxArray *out = mxCreateNumericArray(arraysize, imgsizes, mxDOUBLE_CLASS, mxREAL);
    plhs[0] = out;
    output = (double *) mxGetData(out);
    filter(imgsize, filtersize, imgptr, filterptr, output);
    
}