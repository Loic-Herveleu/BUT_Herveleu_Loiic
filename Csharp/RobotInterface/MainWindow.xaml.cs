using ExtendedSerialPort;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using MouseKeyboardActivityMonitor.WinApi;
using MouseKeyboardActivityMonitor;
using System.Windows.Forms;
using KeyEventArgs = System.Windows.Forms.KeyEventArgs;
using Utilities;
using WpfOscilloscopeControl;
using SciChart.Charting.Visuals;

namespace RobotInterface
{

    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Robot robot = new Robot();
        ReliableSerialPort serialPort1;
        private readonly KeyboardHookListener m_KeyboardHookManager;

        public MainWindow()
        {
            // Set this code once in App.xaml.cs or application startup
            SciChartSurface.SetRuntimeLicenseKey("N+o9D5ioOQMfRcGy8lw1EEsQyXFNhYFG4bBgHA3VEGk4jnECe6LRBeJDmQ/kBmaJJ9EMz274QwbUHPmyhDhRpfegooz/zR+h9qi2tuB5MTqvHi05s1YAuzG3lCuh+B15LMXFiaIs242lEb1eb4U5PQ2KDDXsW7RTayeHDui5hubp7CM6rfIs8niMUQQ2yOBalOd/kQ0s2CCA+V3vIdVfLZGyNHyLU6Fa2xsq42J5Nx3UF3BM1NSA4SX8NLsaDYKIxHaZydTNQO7yMj/rSKk8NsnMglb/gPZpJ+fhkXXzhQJcyPfcj+qQioTSiX6QFk4yoFQ7lEKaMFtbM7r28PBiN3e9ngxEoFechwgKQpxVkhmnAwHi9aHkqyIqHRxTqD0pv/5Jelt+J+oT9malWdtAPpU0kBjBG2JUt7qoXDseglK4dl5IC/xnE9tje90Mj9MhCYFAnT4dSg/VgF0/r5a6Wc3HGqYFoDE0XjF6L8oEO12a0cEGKfRH5RxE9R4r8F7s4A=="); 

            InitializeComponent();
            serialPort1 = new ReliableSerialPort("COM15", 115200, Parity.None, 8, StopBits.One);
            serialPort1.DataReceived += SerialPort1_DataReceived;
            serialPort1.Open();

            DispatcherTimer timerAffichage;
            timerAffichage = new DispatcherTimer();
            timerAffichage.Interval = new TimeSpan(0, 0, 0, 0, 100);
            timerAffichage.Tick += TimerAffichage_Tick;
            timerAffichage.Start();

            m_KeyboardHookManager = new KeyboardHookListener(new GlobalHooker());
            m_KeyboardHookManager.Enabled = true;
            m_KeyboardHookManager.KeyDown += M_KeyboardHookManager_KeyDown;

            oscilloSpeed.AddOrUpdateLine(1, 200, "Ligne1");
            oscilloSpeed.ChangeLineColor(1, Color.FromRgb(0,255,0));

        }

        private void M_KeyboardHookManager_KeyDown(object sender, KeyEventArgs e)
        {
            if (robot.autoControlActivated == false)
            {
                switch (e.KeyCode)
                {
                    case Keys.Left:
                        UartEncodeAndSendMessage(0x0051, 1, new byte[]
                        { (byte)StateRobot.STATE_TOURNE_SUR_PLACE_GAUCHE });
                        break;

                    case Keys.Right:
                        UartEncodeAndSendMessage(0x0051, 1, new byte[]
                        { (byte)StateRobot.STATE_TOURNE_SUR_PLACE_DROITE });
                        break;

                    case Keys.Up:
                        UartEncodeAndSendMessage(0x0051, 1, new byte[]
                        { (byte)StateRobot.STATE_AVANCE });
                        break;

                    case Keys.Down:
                        UartEncodeAndSendMessage(0x0051, 1, new byte[]
                        { (byte)StateRobot.STATE_ARRET });
                        break;

                    case Keys.PageDown:
                        UartEncodeAndSendMessage(0x0051, 1, new byte[]
                        { (byte)StateRobot.STATE_RECULE });
                        break;
                }
            }
        }

        private void TimerAffichage_Tick(object sender, EventArgs e)
        {
            //if(robot.receivedText !="")
            //{
            //    TextBoxReception.Text += "Port serie :";
            //    TextBoxReception.Text += robot.receivedText;
            //    robot.receivedText="";
            //}
            oscilloSpeed.AddPointToLine(1, robot.timestampOdo, robot.positionXOdo);
            asservSpeedDisplay.UpdatePolarOdometrySpeed(robot.vitesseLineaireOdo, robot.vitesseAngulaireOdo);
            while (robot.byteListReceived.Count != 0)
            {
                var c = robot.byteListReceived.Dequeue();
              //TextBoxReception.Text += "0x" + c.ToString("X2") + " ";
                DecodeMessage(c);
            }
        }


        public void SerialPort1_DataReceived(object sender, DataReceivedArgs e)
        {
            foreach (var b in e.Data)
                robot.byteListReceived.Enqueue(b);
        }

        string text;
        bool toggle = false;
        private void buttonEnvoyer_Click(object sender, RoutedEventArgs e)
        {
            if (toggle)
            {
                buttonEnvoyer.Background = Brushes.RoyalBlue;
            }
            else
            {
                buttonEnvoyer.Background = Brushes.Beige;
            }
            toggle = !toggle;
            SendMessage();
        }
        private void SendMessage()
        {
            serialPort1.WriteLine(TextBoxEmission.Text);
            TextBoxEmission.Text = "";

        }

        private void TextBoxEmission_KeyUp(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();

            }
        }

        private void buttonClear_Click(object sender, RoutedEventArgs e)
        {
            TextBoxReception.Text = "";
        }

        private void buttonTest_Click(object sender, RoutedEventArgs e)
        {
            //byte [] byteList=new byte [20];
            //for (int i= 0; i < 20; i++)
            //{
            //    byteList[i] = (byte)(2 * i);
            //}
            //serialPort1.Write(byteList,0,20);

            byte[] array = Encoding.ASCII.GetBytes("Bonjour");
            //byte[] ledTest = { 0x00, 0x01, 0x02 };
            UartEncodeAndSendMessage(0x0080, 7, array);
            // ProcessDecodedMessage(0x0080, 7, array);
            //  ProcessDecodedMessage(0x0030, 3, ledTest);
        }
        byte CalculateChecksum(int msgFunction, int msgPayloadLength, byte[] msgPayload)
        {
            byte checksum = 0x00;
            checksum ^= 0xFE;
            checksum ^= (byte)(msgFunction >> 8);
            checksum ^= (byte)(msgFunction >> 0);
            checksum ^= (byte)(msgPayloadLength >> 8);
            checksum ^= (byte)(msgPayloadLength >> 0);

            for (int i = 0; i < msgPayloadLength; i++)
            {
                checksum ^= msgPayload[i];
            }
            return checksum;
        }
        void UartEncodeAndSendMessage(int msgFunction, int msgPayloadLength, byte[] msgPayload)
        {
            byte[] message = new byte[msgPayloadLength + 6];
            int pos = 0;
            message[pos++] = 0xFE;
            message[pos++] = (byte)(msgFunction >> 8);
            message[pos++] = (byte)(msgFunction >> 0);
            message[pos++] = (byte)(msgPayloadLength >> 8);
            message[pos++] = (byte)(msgPayloadLength >> 0);

            for (int i = 0; i < msgPayloadLength; i++)
            {
                message[pos++] = msgPayload[i];
            }
            message[pos] = CalculateChecksum(msgFunction, msgPayloadLength, msgPayload);
            serialPort1.Write(message, 0, msgPayloadLength + 6);
        }
        public enum StateReception
        {
            Waiting,
            FunctionMSB,
            FunctionLSB,
            PayloadLengthMSB,
            PayloadLengthLSB,
            Payload,
            CheckSum
        }

        StateReception rcvState = StateReception.Waiting;
        int msgDecodedFunction = 0;
        int msgDecodedPayloadLength = 0;
        byte[] msgDecodedPayload;
        int msgDecodedPayloadIndex = 0;

        private void DecodeMessage(byte c)
        {
            switch (rcvState)
            {
                case StateReception.Waiting:

                    if (c == 0xFE)
                    {
                        rcvState = StateReception.FunctionMSB;
                    }
                    break;

                case StateReception.FunctionMSB:

                    msgDecodedFunction = c << 8;
                    rcvState = StateReception.FunctionLSB;

                    break;

                case StateReception.FunctionLSB:

                    msgDecodedFunction = c << 0;
                    rcvState = StateReception.PayloadLengthMSB;

                    break;

                case StateReception.PayloadLengthMSB:

                    msgDecodedPayloadLength = c << 8;
                    rcvState = StateReception.PayloadLengthLSB;

                    break;

                case StateReception.PayloadLengthLSB:

                    msgDecodedPayloadLength = c << 0;
                    msgDecodedPayload = new byte[msgDecodedPayloadLength];
                    msgDecodedPayloadIndex = 0;
                    rcvState = StateReception.Payload;

                    break;

                case StateReception.Payload:

                    if (msgDecodedPayloadIndex < msgDecodedPayloadLength)
                    {
                        msgDecodedPayload[msgDecodedPayloadIndex] = c;
                        msgDecodedPayloadIndex++;

                        if (msgDecodedPayloadIndex == msgDecodedPayloadLength)
                        {
                            rcvState = StateReception.CheckSum;
                        }
                    }


                    break;

                case StateReception.CheckSum:

                    if (CalculateChecksum(msgDecodedFunction, msgDecodedPayloadLength, msgDecodedPayload) == c)
                    {
                        TextBoxReception.Text += "OK\n";
                        ProcessDecodedMessage(msgDecodedFunction, msgDecodedPayloadLength, msgDecodedPayload);
                    }
                    rcvState = StateReception.Waiting;
                    break;

                default:
                    rcvState = StateReception.Waiting;
                    break;
            }
        }

        public enum Function
        {
            Texte = 0x0080,
            Led = 0x0020,
            DistanceTelemetre = 0x0030,
            Vitesse = 0x0040,
            RobotState = 0x0050,
            ManuControl = 0x0052,
            PositionData = 0x0061,
            VitesseData = 0x0062,
            Correcteur = 0x0063
        }
        public enum StateRobot
        {
            STATE_ATTENTE = 0,
            STATE_ATTENTE_EN_COURS = 1,
            STATE_AVANCE = 2,
            STATE_AVANCE_EN_COURS = 3,
            STATE_TOURNE_GAUCHE = 4,
            STATE_TOURNE_GAUCHE_EN_COURS = 5,
            STATE_TOURNE_DROITE = 6,
            STATE_TOURNE_DROITE_EN_COURS = 7,
            STATE_TOURNE_SUR_PLACE_GAUCHE = 8,
            STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS = 9,
            STATE_TOURNE_SUR_PLACE_DROITE = 10,
            STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS = 11,
            STATE_ARRET = 12,
            STATE_ARRET_EN_COURS = 13,
            STATE_RECULE = 14,
            STATE_RECULE_EN_COURS = 15
        }


        void ProcessDecodedMessage(int msgFunction, int msgPayloadLength, byte[] msgPayload)
        {
            switch ((Function)msgFunction)
            {

                case Function.Texte:
                    TextBoxReception.Text += Encoding.UTF8.GetString(msgPayload, 0, msgPayloadLength);
                    break;

                case Function.Led:
                    switch (msgPayload[0])
                    {
                        case 0:

                            if (msgPayload[1] == 0x00)
                            {
                                checkBoxLed1.IsChecked = false;
                            }
                            else if (msgPayload[1] == 0x01)
                            {
                                checkBoxLed1.IsChecked = true;
                            }
                            break;

                        case 1:

                            if (msgPayload[1] == 0x00)
                            {
                                checkBoxLed1.IsChecked = false;
                            }
                            else if (msgPayload[1] == 0x01)
                            {
                                checkBoxLed1.IsChecked = true;
                            }
                            break;

                        case 2:

                            if (msgPayload[1] == 0x00)
                            {
                                checkBoxLed1.IsChecked = false;
                            }
                            else if (msgPayload[1] == 0x01)
                            {
                                checkBoxLed1.IsChecked = true;
                            }
                            break;

                    }
                    break;

                case Function.DistanceTelemetre:

                    labelIRC.Content = "IR Centre : " + msgPayload[1] + " cm";
                    labelIRG.Content = "IR Gauche : " + msgPayload[0] + " cm";
                    labelIRD.Content = "IR Droit : " + msgPayload[2] + " cm";
                    break;

                case Function.Vitesse:
                    labelVG.Content = "Vitesse Gauche : " + msgPayload[1];
                    labelVD.Content = "Vitesse Droite : " + msgPayload[0];
                    break;

                case Function.RobotState:

                    int instant = (((int)msgPayload[1]) << 24) + (((int)msgPayload[2]) << 16) + (((int)msgPayload[3]) << 8) + ((int)msgPayload[4]);
                    //TextBoxReception.Text += "\nRobot␣State␣:␣" + ((StateRobot)(msgPayload[0])).ToString() + "␣-␣" + instant.ToString() + "␣ms";
                    break;

                case Function.PositionData:

                    robot.timestampOdo = (((int)msgPayload[0]) << 24) + (((int)msgPayload[1]) << 16) + (((int)msgPayload[2]) << 8) + ((int)msgPayload[3]);
                    labelTimestamp.Content = "Timestamp : " + robot.timestampOdo;
                   
                    robot.positionXOdo = BitConverter.ToSingle(msgPayload, 4);
                    labelPosX.Content = "PosX : " + robot.positionXOdo;

                    robot.positionYOdo = BitConverter.ToSingle(msgPayload, 8);
                    labelPosY.Content = "PosY : " + robot.positionYOdo;

                    robot.angleRadianOdo = BitConverter.ToSingle(msgPayload, 12);
                    labelAngleRad.Content = "Angle : " + robot.angleRadianOdo;

                    robot.vitesseLineaireOdo = BitConverter.ToSingle(msgPayload, 16);
                    labelVLineaire.Content = "Vitesse linéaire : " + robot.vitesseLineaireOdo;

                    robot.vitesseAngulaireOdo = BitConverter.ToSingle(msgPayload, 20);
                    labelVAngulaire.Content = "Vitesse angulaire : " + robot.vitesseAngulaireOdo;

                    //  int posData = 
                    //  TextBoxReception.Text += "Data : "+ (msgPayload).ToString();
                    break;

                case Function.VitesseData:

                    robot.vitesseM1= BitConverter.ToSingle(msgPayload, 0);
                    robot.vitesseM2 = BitConverter.ToSingle(msgPayload, 4);
                    asservSpeedDisplay.UpdateIndependantOdometrySpeed(robot.vitesseM1, robot.vitesseM2);
                    break;
            }
        }

        private void checkBoxMode_Checked(object sender, RoutedEventArgs e)
        {
            robot.autoControlActivated = false;
            UartEncodeAndSendMessage((int)Function.ManuControl, 1, new byte[]{1});

        }

        private void checkBoxMode_Unchecked(object sender, RoutedEventArgs e)
        {
            robot.autoControlActivated = true;
            UartEncodeAndSendMessage((int)Function.ManuControl, 1, new byte[] { 0 });
        }

        private void buttonPIDX_Click(object sender, RoutedEventArgs e)
        {
            byte[] payloadPID = new byte[29];

            UartEncodeAndSendMessage(0x0063, 29, payloadPID);
            TextBoxEmission.Text = "";
        }

        private void buttonPIDT_Click(object sender, RoutedEventArgs e)
        {
            byte[] payloadPID = new byte[29];

            UartEncodeAndSendMessage(0x0063, 29, payloadPID);
            TextBoxEmission.Text = "";
        }
    }
}

