#ifndef STATEGRAPH_H
#define STATEGRAPH_H

#include "graph.h"

enum emit_errors
{
    EMIT_SUCCESS = 0,
    EMIT_INVALID_EVENT = 1,
    EMIT_IDLE,

};

class StateGraph : public TGraph
{
private:
    qint16 active_node;


public:
    StateGraph();
    ~StateGraph();
    int create_m(unsigned int,unsigned int);
    void reset_active_node();
    qint16 get_active_node();
    int emit_event(qint16);
};

#endif // STATEGRAPH_H
