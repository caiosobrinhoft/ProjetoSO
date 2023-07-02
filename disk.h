#include "process.h"
#include "list.h"
#define DISK_TRACK_LIMIT (200)
#define DISK_REQUEST 4;
#define DISK_FINISH 5;
#define DISK_OPERATION_TIME (5000)
#define DISK_TRACK_MOVE_TIME (100)
#define PRINT_FINISH 15

typedef struct DiskRequest {
    process_t* process;
    int track;
    int read;
    int turnaround;
} disk_request_t;

typedef struct DiskScheduler {
    list_t* pending_requests;
    int forward_dir;
    int curr_track;
} disk_scheduler_t;

disk_request_t* create_disk_request();

void disk_request(process_t* process, disk_scheduler_t *disk_scheduler, int track, int read);
void interruptControl(DISK_REQUEST, process_t process);

