#include "getfeatures.h"

bool getFeatures(SoundData*& sndData)
{
    // the dimension of the pointers in and out
    //int N = 2;
    int N = sndData->ckDataSize();

    // the pointer that stores the input data.
    //fftw_complex *in;
    // the pointer that stores the output data.
    //fftw_complex *out;
    //in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
    //out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);


    int input_size = sndData->audio_data_.size();
    int output_size = (input_size/2 + 1);




    double *input_buffer = static_cast<double*>(fftw_malloc(N * sizeof(double)));
    fftw_complex *out = static_cast<fftw_complex*>(fftw_malloc(N * sizeof(fftw_complex)));


    //Assign sound samples to double array
    input_buffer = (double*)sndData->audio_data_.data();
    fftw_plan my_plan;

    //Create plan
    my_plan = fftw_plan_dft_r2c_1d(input_size, input_buffer, out, FFTW_ESTIMATE);


/*
    double reout[input_size];
    double imgout[input_size];
    double magnitude[input_size/2];

    long ffond = 0.0; // Position of the frequency
    double max = 0; // Maximal amplitude

    for (int i = 0; i < input_size/2; i++)
    {
        reout[i] = out[i][0];
        imgout[i] = out[i][1];
        cout << imgout[i] << endl;
        magnitude[i] = sqrt(reout[i]*reout[i] + imgout[i]*imgout[i]); //Calculate magnitude of first
        double t = sqrt(reout[i]*reout[i] + imgout[i]*imgout[i]);
        //qDebug() << t;


    }
*/


    /***
     * int FFTW_FORWARD: FFTW_FORWARD is an integer constant of the package
     * that tells to the function that the FFT to perform must be the forward
     * one. To perform the bacward one, we will introduce FFTW_BACKWARD. To
     * see the differences between these two, the reader can refer to
     * section 1.
     * */

    /***
     * unsigned FFTW_ESTIMATE: FFTW_ESTIMATE is a flag that tells to the
     * function how well must be optimized, with respect to the computational
     * time, the FFT algorithm. If we are getting started to the package we
     * will use this flag. For other values of this flag the reader can
     * consult appendix A.
     * */

    //my_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);


    /***
     * These routines create plans for n0 by n1 two-dimensional (2d)
     * transforms and n0 by n1 by n2 3d transforms, respectively.
     * All of these transforms operate on contiguous arrays in the
     * C-standard row-major order, so that the last dimension has
     * the fastest-varying index in the array.
     *
     * my_plan = fftw_plan_dft_2d(int n0, int n1,
     *                         fftw_complex *in, fftw_complex *out,
     *                         int sign, unsigned flags);
     * */
    /*my_plan = fftw_plan_dft_2d(n0, n1,
                               in, out,
                               sign, flags);*/

    /***
     * performs the FFT stored in my_plan.
     * */
    fftw_execute(my_plan);

    /***
     * deallocate the memory stored by the plan and the pointers.
     * Note that for the pointers we use fftw_free and not the
     * stdlib.h function free
     * */
    fftw_destroy_plan(my_plan);
    fftw_free(input_buffer);
    fftw_free(out);


    return false;
}

