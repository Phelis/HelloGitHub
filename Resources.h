#ifndef RESOURCE_H
#define RESOURCE_H

typedef struct data {
    int id;		// index
    char* buf;		// a buffer
} Datagram;		// diagram constains data, called as datagram

// load resource
void load_resource(Datagram *data);

// save resource
void save_resource(Datagram *data);

#endif