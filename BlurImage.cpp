#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

char window_name1[] = "Unprocessed Image";
char window_name2[] = "Processed Image";

int main( int argc, char** argv )
{
    /// Load the source image
    auto src = imread( argv[1], ImreadModes::IMREAD_COLOR );

    namedWindow( window_name1, WINDOW_AUTOSIZE );
    imshow("Unprocessed Image",src);

    auto dst = src.clone();
    GaussianBlur( src, dst, Size( 15, 15 ), 0, 0 );

    namedWindow( window_name2, WINDOW_AUTOSIZE );
    imshow("Processed Image",dst);

    waitKey();
    return 0;
}
