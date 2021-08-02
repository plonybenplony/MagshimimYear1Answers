#include "view.h"

/**
play the movie!!
display the images each for the duration of the frame one by one and close the window
input: a linked list of frames to display
output: none
**/
void play(FrameNode* list)
{
	cvNamedWindow("Display window", CV_WINDOW_AUTOSIZE); //create a window
	FrameNode* head = list; // Saving the first node
	int imgNum = 1, playing = 1; // the index of the image, and whether or not we should keep playing
	IplImage* image; // gets the image
	while (playing)
	{
		while (list != 0)
		{
			image = cvLoadImage(list->frame->path, 1);
			IplImage* pGrayImg = 0;
			pGrayImg = cvCreateImage(cvSize(image->width, image->height), image->depth, 1);

			if (!image) //The image is empty - shouldn't happen since we checked already.
			{
				printf("Could not open or find image number %d", imgNum);
			}
			else
			{
				cvShowImage("Display window", image); //display the image

				if (cvWaitKey(list->frame->duration) == 27) { playing = 0; break; } //wait and listen to exit

				list = list->next;
				cvReleaseImage(&image);
			}

			imgNum++;
		}

		list = head; // rewind
	}

	cvDestroyWindow("Display window");
	return;
}