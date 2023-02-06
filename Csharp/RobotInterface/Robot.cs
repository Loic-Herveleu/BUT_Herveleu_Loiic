﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RobotInterface
{
    public class Robot
    {
        public string receivedText = "";
        public float distanceTelemetreDroit;
        public float distanceTelemetreCentre;
        public float distanceTelemetreGauche;
        public float positionXOdo;
        public float positionYOdo;
        public float angleRadianOdo;
        public float vitesseLineaireOdo;
        public float vitesseAngulaireOdo;
        public float vitesseM1;
        public float vitesseM2;
        public int timestampOdo;
        public bool autoControlActivated=true;
        public Queue<byte> byteListReceived = new Queue<byte>();

        public Robot()
        {
        }
       
    }
}
