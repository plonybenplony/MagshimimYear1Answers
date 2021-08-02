#ifndef VIEW_H
#define VIEW_H

#define CV_IGNORE_DEBUG_BUILD_GUARD
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

#define GIF_REPEAT 5

void play(FrameNode *list);

#endif