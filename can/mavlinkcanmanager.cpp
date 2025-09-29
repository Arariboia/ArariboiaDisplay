#include "mavlinkcanmanager.h"
#include <QDebug>

MavlinkCanManager::MavlinkCanManager(QObject *parent) : QObject(parent)
{

}

bool MavlinkCanManager::handle_can_frame(const QCanBusFrame &message){
    if(message.frameId() != 0xABC){
        return false;
    }

    mavlink_status_t status;
    mavlink_message_t msg;
    uint8_t chan = MAVLINK_COMM_2;
    for(int i = 0; i < message.payload().size(); i++){
        if(mavlink_parse_char(chan, message.payload().at(i), &msg, &status)){
            qDebug() << "MAVLINK " << msg.msgid;
            if(msg.msgid == MAVLINK_MSG_ID_MPPT){
                mavlink_mppt_t mppt;
                mavlink_msg_mppt_decode(&msg, &mppt);
                emit MPPTDataReceived(mppt);
            }
            else if(msg.msgid == MAVLINK_MSG_ID_INSTRUMENTATION){
                mavlink_instrumentation_t inst;
                mavlink_msg_instrumentation_decode(&msg, &inst);
                emit InstrumentationDataReceived(inst);
            }
            else if(msg.msgid == MAVLINK_MSG_ID_ELETRONIC_PROPULSION){
                mavlink_eletronic_propulsion_t prop;
                mavlink_msg_eletronic_propulsion_decode(&msg, &prop);
                emit PropulsionDataReceived(prop);
            }
            else if(msg.msgid == MAVLINK_MSG_ID_MPPT_STRINGS){
                mavlink_mppt_strings_t mpptString;
                mavlink_msg_mppt_strings_decode(&msg, &mpptString);
                emit MPPTStringsDataReceived(mpptString);
            }
        }
    }

    return true;
}
