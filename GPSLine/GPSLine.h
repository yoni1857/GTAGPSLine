/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include <iostream>
#include <fstream>
#include <iterator>

#include "plugin.h"
#include "RenderWare.h"
#include "common.h"
#include "CMenuManager.h"
#include "CRadar.h"
#include "CGeneral.h"
#include "CWorld.h"
#include "CPools.h"
#include "CVehicle.h"
#include "CPed.h"
#include "CObject.h"
#include "CPickup.h"
#include "CPickups.h"
#include "CTheScripts.h"
#include "CStreaming.h"
#include "RenderWare.h"
#include "CFont.h"
#include "d3d9.h"
#include "extensions/ScriptCommands.h"
#include "StringUtils.h"

#define MAX_NODE_POINTS 50000
#define GPS_LINE_WIDTH  4.0f
#define GPS_LINE_R  180
#define GPS_LINE_G  24
#define GPS_LINE_B  24
#define GPS_LINE_A  255
#define MAX_TARGET_DISTANCE 10.0f

class GPSLine {
private:
    std::ofstream logfile;

    // These variables will be used for the gps route following the target blip set by the player
    bool GPSLine::targetRouteShown;
    float GPSLine::targetDistance;
    short GPSLine::targetNodesCount;

    CNodeAddress GPSLine::t_ResultNodes[MAX_NODE_POINTS];
    CVector2D GPSLine::t_NodePoints[MAX_NODE_POINTS];
    RwIm2DVertex GPSLine::t_LineVerts[MAX_NODE_POINTS * 4];

    // These will be used for mission objectives
    bool GPSLine::missionRouteShown;
    float GPSLine::missionDistance;
    short GPSLine::missionNodesCount;

    CNodeAddress GPSLine::m_ResultNodes[MAX_NODE_POINTS];
    CVector2D GPSLine::m_NodePoints[MAX_NODE_POINTS];
    RwIm2DVertex GPSLine::m_LineVerts[MAX_NODE_POINTS * 4];

    char GPSLine::pathNodesToStream[1024];
    int GPSLine::pathNodes[50000];

    void GPSLine::Setup2dVertex(RwIm2DVertex& vertex, float x, float y, short color);

    // Self explanatory.
    void GPSLine::calculatePath(CVector destPosn, short& nodesCount, CNodeAddress* resultNodes, CVector2D* nodePoints, float& gpsDistance);

    void GPSLine::renderPath(short color, short& nodesCount, bool& gpsShown, CNodeAddress* resultNodes, CVector2D* nodePoints, float& gpsDistance, RwIm2DVertex* lineVerts);

public:

    GPSLine();

} gPSLine;