#ifndef FILTERS_H
#define FILTERS_H

void SummerTime_Filter(gdImagePtr image, FILE *Output, char *path );

void Glow_Filter(gdImagePtr image, FILE *Output, char *path );

void OldSchool_Filter(gdImagePtr image, FILE *Output, char *path );

void RedFlag_Filter(gdImagePtr image, FILE *Output, char *path );

void Vogue_Filter(gdImagePtr image, FILE *Output, char *path );

void WinterFrost_Filter(gdImagePtr image, FILE *Output, char *path);

void TimeOClock_Filter(gdImagePtr image, FILE *Output, char *path);

void WeekDay_Filter(gdImagePtr image, FILE *Output, char *path  );

#endif
