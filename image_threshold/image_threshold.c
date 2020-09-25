



#include "mex.h"
#include "matrix.h"

void thresholdold(int height, int width, double threshold, const double *input, double *output)
{
    int size = height * width;
    
    
    if (threshold > 1.0)
        threshold = 1.0;
    if (threshold < 0.0)
        threshold = 0.0;
    
    for (int i = 0; i < size; i++)
    {
        if (input[i] >= threshold)
            output[i] = 1.0;
        else
            output[i] = 0.0;
    }
}

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int width, height;
    double *input, *output, threshold;
 
    
    // I/O errors will be "detected and rejected"
    if (nrhs != 2)
        mexErrMsgTxt("Error:  two input arguements required.");
    if (nlhs != 1)
        mexErrMsgTxt("Error:  one output required.");
    if ( !mxIsDouble(prhs[0]) )
        mexErrMsgTxt("Error:  input image must be 64-bit floating point.");
    if ( !mxIsScalar(prhs[1]) )
            mexErrMsgTxt("Error:  thresholdold value must be a scalar number.");
            
    // get dimensions of image
    const mwSize *dims = mxGetDimensions(prhs[0]);
    height = dims[0];
    width = dims[1];
    

    input = (double *) mxGetPr(prhs[0]);
     threshold = mxGetScalar(prhs[1]);
    
  
    mxArray *out = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
    plhs[0] = out;
    output = (double *) mxGetData(out);
    

    thresholdold(width, height, threshold, input, output);
    
}
