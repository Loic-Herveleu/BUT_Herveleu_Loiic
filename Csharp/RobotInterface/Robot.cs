using System;
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
        public float kpX;
        public float kiX;
        public float kdX;
        public float erPropX;
        public float erIntegX;
        public float erDerivX;
        public float kpT;
        public float kiT;
        public float kdT;
        public float erPropT;
        public float erIntegT;
        public float erDerivT;
        public float consigneX;
        public float consigneT;
        public float erreurX;
        public float erreurT;
        public float corrPX;
        public float corrIX;
        public float corrDX;
        public float corrPT;
        public float corrIT;
        public float corrDT;


        public int timestampOdo;
        public bool autoControlActivated=true;
        public Queue<byte> byteListReceived = new Queue<byte>();

        public Robot()
        {
        }
       
    }
}
