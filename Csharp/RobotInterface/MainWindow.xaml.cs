using System;
using System.Collections.Generic;
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

namespace RobotInterface
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

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
            if (TextBoxEmission.Text != "" && TextBoxEmission.Text != "\r\n")
            {
                TextBoxReception.Text += "Reçu :";
                TextBoxReception.Text += TextBoxEmission.Text;
                TextBoxEmission.Text = "";
            }
            else
            {
                TextBoxEmission.Text = "";
            }

        }

        private void TextBoxEmission_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();

            }
        }
    }
}
