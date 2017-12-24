#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
#include "profile.h"
#include "list.h"
#include "vector.h"
#include "data.h"

void profileInsert(Vector * vect, List * list)
{

	int i;
	struct timeval start, stop;
	gettimeofday(&start, NULL);

	for(i = 0; i< 1000; i++){

			insertVector(vect, i, (Data) {i});

	}
	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	printf("\n\tProfile Insert Vectors\n");
	printf("\tstart time = %ld\n", start_time);
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	printf("\tstop time = %ld\n", stop_time);
	float profile_time = stop_time - start_time;
	printf("\tprofile time = %lf\n", profile_time);



        gettimeofday(&start, NULL);

        for(i = 0; i< 1000; i++){

	           insertList(list, i, (Data) {i});

        }
        gettimeofday(&stop, NULL);
        start_time = (start.tv_sec* 1000000) + start.tv_usec;
        printf("\n\tProfile Insert Lists\n");
        printf("\tstart time = %ld\n", start_time);
        stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
        printf("\tstop time = %ld\n", stop_time);
        profile_time = stop_time - start_time;
        printf("\tprofile time = %lf\n", profile_time);


}

void profileRead(Vector * vect, List * list)
{

	struct timeval start, stop;
	gettimeofday(&start, NULL);
	int counter=0;
	int random_index;
	for(counter = 0; counter< 100; counter++){
		random_index = rand() % 100;
		readVector(vect, random_index);
	}
	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	printf("\n\tProfile Read Vectors\n");
	printf("\tstart time = %ld\n", start_time);
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	printf("\tstop time = %ld\n", stop_time);
	float profile_time = stop_time - start_time;
	printf("\tprofile time = %lf\n", profile_time);


	gettimeofday(&start, NULL);
	for(counter = 0; counter< 100; counter++){
                random_index = rand() % 100;
                readData(list, random_index);
        }
        gettimeofday(&stop, NULL);
        start_time = (start.tv_sec* 1000000) + start.tv_usec;
        printf("\n\tProfile Read Lists\n");
        printf("\tstart time = %ld\n", start_time);
        stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
        printf("\tstop time = %ld\n", stop_time);
        profile_time = stop_time - start_time;
        printf("\tprofile time = %lf\n", profile_time);


}

void profileRemove(Vector * vect, List * list)
{
	struct timeval start, stop;
	gettimeofday(&start, NULL);
	int counter;
	int random_index;
	for(counter = 0; counter<100; counter++){
		random_index = rand() % 100;
		removeVector(vect, random_index);

	}
	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	printf("\n\tProfile Remove Vectors\n");
	printf("\tstart time = %ld\n", start_time);
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	printf("\tstop time = %ld\n", stop_time);
	float profile_time = stop_time - start_time;
	printf("\tprofile_time = %lf\n", profile_time);

	gettimeofday(&start, NULL);
	for(counter = 0; counter< 100; counter++){
                random_index = rand() % 100;
                removeVector(vect, random_index);

        }
        gettimeofday(&stop, NULL);
        start_time = (start.tv_sec* 1000000) + start.tv_usec;
        printf("\n\tProfile Remove Lists\n");
        printf("\tstart time = %ld\n", start_time);
        stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
        printf("\tstop time = %ld\n", stop_time);
        profile_time = stop_time - start_time;
        printf("\tprofile_time = %lf\n", profile_time);

}
