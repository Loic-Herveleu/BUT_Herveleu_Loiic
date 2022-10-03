//void OperatingSystemLoop(void) {
//    switch (stateRobot) {
//        case STATE_ATTENTE:
//            timestamp = 0;
//            PWMSetSpeedConsigne(0, MOTEUR_G);
//            PWMSetSpeedConsigne(0, MOTEUR_D);
//            stateRobot = STATE_ATTENTE_EN_COURS;
//
//        case STATE_ATTENTE_EN_COURS:
//            if (timestamp > 1000)
//                stateRobot = STATE_AVANCE;
//            break;
//
//        case STATE_AVANCE:
//            PWMSetSpeedConsigne(25, MOTEUR_G);
//            PWMSetSpeedConsigne(25, MOTEUR_D);
//            stateRobot = STATE_AVANCE_EN_COURS;
//            break;
//            
//        case STATE_AVANCE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_GAUCHE:
//            PWMSetSpeedConsigne(13, MOTEUR_G);
//            PWMSetSpeedConsigne(0, MOTEUR_D);
//            stateRobot = STATE_TOURNE_GAUCHE_EN_COURS;
//            break;
//        case STATE_TOURNE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_DROITE:
//            PWMSetSpeedConsigne(0, MOTEUR_G);
//            PWMSetSpeedConsigne(13, MOTEUR_D);
//            stateRobot = STATE_TOURNE_DROITE_EN_COURS;
//            break;
//        case STATE_TOURNE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//            // case STATE_RALENTIT_CENTRE:
//            //     PWMSetSpeedConsigne(17, MOTEUR_G);
//            //     PWMSetSpeedConsigne(17, MOTEUR_D);
//            //     stateRobot = STATE_RALENTIT_CENTRE_EN_COURS;
//
//            // case STATE_RALENTIT_CENTRE_EN_COURS:
//            //     SetNextRobotStateInAutomaticMode();
//
//        case STATE_TOURNE_SUR_PLACE_GAUCHE:
//            PWMSetSpeedConsigne(10, MOTEUR_G);
//            PWMSetSpeedConsigne(-10, MOTEUR_D);
//            stateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS;
//            break;
//        case STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_DROITE:
//            PWMSetSpeedConsigne(-10, MOTEUR_G);
//            PWMSetSpeedConsigne(10, MOTEUR_D);
//            stateRobot = STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_LEGER_GAUCHE:
//            PWMSetSpeedConsigne(12, MOTEUR_G);
//            PWMSetSpeedConsigne(0, MOTEUR_D);
//            stateRobot = STATE_LEGER_GAUCHE_EN_COURS;
//            break;
//
//        case STATE_LEGER_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_LEGER_DROIT:
//            PWMSetSpeedConsigne(0, MOTEUR_G);
//            PWMSetSpeedConsigne(12, MOTEUR_D);
//            stateRobot = STATE_LEGER_DROIT_EN_COURS;
//            break;
//
//        case STATE_LEGER_DROIT_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_RALENTIT_GAUCHE:
//            PWMSetSpeedConsigne(12, MOTEUR_G);
//            PWMSetSpeedConsigne(10, MOTEUR_D);
//            stateRobot = STATE_RALENTIT_GAUCHE_EN_COURS;
//            break;
//
//        case STATE_RALENTIT_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_RALENTIT_DROIT:
//            PWMSetSpeedConsigne(10, MOTEUR_G);
//            PWMSetSpeedConsigne(12, MOTEUR_D);
//
//            stateRobot = STATE_RALENTIT_DROIT_EN_COURS;
//
//            break;
//
//        case STATE_RALENTIT_DROIT_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//
//        default:
//            stateRobot = STATE_ATTENTE;
//            break;
//    }
//}
//
//void SetNextRobotStateInAutomaticMode() {
//    unsigned char positionObstacle = PAS_D_OBSTACLE;
//
//    //Détermination de la position des obstacles en fonction des télémètres
//  //  if (robotState.distanceTelemetreDroit < 55 && robotState.distanceTelemetreCentre > 60 && robotState.distanceTelemetreGauche > 60) //Obstacle à droite
////        positionObstacle = OBSTACLE_A_DROIT_PROCHE;
////    else if (robotState.distanceTelemetreDroit > 60 && robotState.distanceTelemetreCentre > 60 && robotState.distanceTelemetreGauche < 55) //Obstacle à gauche
////        positionObstacle = OBSTACLE_A_GAUCHE_PROCHE;
//   /* else*/ if (robotState.distanceTelemetreDroit < 47 && robotState.distanceTelemetreCentre > 53 && robotState.distanceTelemetreGauche > 53) //Obstacle à droite
//        positionObstacle = OBSTACLE_A_DROITE;
//    else if (robotState.distanceTelemetreDroit > 53 && robotState.distanceTelemetreCentre > 53 && robotState.distanceTelemetreGauche < 47) //Obstacle à gauche
//        positionObstacle = OBSTACLE_A_GAUCHE;
//    else if (robotState.distanceTelemetreDroit < 47 && robotState.distanceTelemetreGauche > 53) //Obstacle à droite
//        positionObstacle = OBSTACLE_A_DROITE;
//    else if (robotState.distanceTelemetreDroit > 53 && robotState.distanceTelemetreGauche < 47) //Obstacle à gauche
//        positionObstacle = OBSTACLE_A_GAUCHE;
//    else if (robotState.distanceTelemetreCentre < 50 && !STATE_AVANCE_EN_COURS) //Obstacle en face
//        positionObstacle = OBSTACLE_EN_FACE;
//    else if (robotState.distanceTelemetreCentre < 60 && STATE_AVANCE_EN_COURS) //Obstacle en face
//        positionObstacle = OBSTACLE_EN_FACE;
//    else if (robotState.distanceTelemetreDroit > 60 && robotState.distanceTelemetreCentre > 60 && robotState.distanceTelemetreGauche > 60) //pas d?obstacle
//        positionObstacle = PAS_D_OBSTACLE;
//    else if (robotState.distanceTelemetreEXTDroit < 45 && robotState.distanceTelemetreDroit > 50)
//        positionObstacle = OBSTACLE_FLANC_DROIT;
//    else if (robotState.distanceTelemetreEXTGauche < 45 && robotState.distanceTelemetreGauche > 50)
//        positionObstacle = OBSTACLE_FLANC_GAUCHE;
//    else if (robotState.distanceTelemetreEXTGauche <30 && robotState.distanceTelemetreEXTDroit<30)
//        positionObstacle = OBSTACLE_EN_FACE;
//      else if (robotState.distanceTelemetreGauche <30 && robotState.distanceTelemetreDroit<30)
//        positionObstacle = OBSTACLE_EN_FACE;
//
//    //Détermination de l?état à venir du robot
//    if (positionObstacle == PAS_D_OBSTACLE) 
//        nextStateRobot = STATE_AVANCE;
//    else if (positionObstacle == OBSTACLE_A_DROITE)
//        nextStateRobot = STATE_TOURNE_GAUCHE;
//    else if (positionObstacle == OBSTACLE_A_GAUCHE)
//        nextStateRobot = STATE_TOURNE_DROITE;
//    else if (positionObstacle == OBSTACLE_EN_FACE && robotState.distanceTelemetreGauche > robotState.distanceTelemetreDroit)
//        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;
//    else if (positionObstacle == OBSTACLE_EN_FACE && robotState.distanceTelemetreDroit > robotState.distanceTelemetreGauche)
//        nextStateRobot = STATE_TOURNE_SUR_PLACE_DROITE;
//        // else if (positionObstacle == OBSTACLE_EN_FACE_PROCHE)
//        //   nextStateRobot = STATE_RALENTIT_CENTRE;
//    else if (positionObstacle == OBSTACLE_FLANC_DROIT)
//        nextStateRobot = STATE_LEGER_GAUCHE;
//    else if (positionObstacle == OBSTACLE_FLANC_GAUCHE)
//        nextStateRobot = STATE_LEGER_DROIT;
//    else if (positionObstacle == OBSTACLE_A_DROIT_PROCHE)
//        nextStateRobot = STATE_RALENTIT_GAUCHE;
//    else if (positionObstacle == OBSTACLE_A_GAUCHE_PROCHE)
//        nextStateRobot = STATE_RALENTIT_DROIT;
//
//    //Si l?on n?est pas dans la transition de l?étape en cours
//    if (nextStateRobot != stateRobot - 1)
//        stateRobot = nextStateRobot;
//}
