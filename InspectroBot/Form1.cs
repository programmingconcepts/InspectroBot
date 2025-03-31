using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Http;
using System.Diagnostics;

namespace InspectroBot
{
    public partial class Form1: Form
    {
        HttpClient client = new HttpClient();

        int speed = 200;
        int accelaration = 2;

        bool robotControlEnabled = false;

        public Form1()
        {
            InitializeComponent();

            WebView.EnsureCoreWebView2Async(null);
        }

        private bool ValidateIP(string ip)
        {
            bool result = true;
            for (int i = 0; i < ip.Length; i++)
            {
                if (ip[i] >= 46 && ip[i] <= 57 && ip[i] != 47)
                {
                    result = true;
                }
                else return false;
            }
            return result;
        }

        private void TBIP_TextChanged(object sender, EventArgs e)
        {
            if (!ValidateIP(TBIP.Text))
            {
                try
                {
                    TBIP.Text = TBIP.Text.Remove(TBIP.Text.Length - 1);
                    TBIP.Focus();
                    TBIP.SelectionStart = TBIP.Text.Length;
                }
                catch
                {
                    // ignore
                }
            }
        }

        private void btnStartCam_Click(object sender, EventArgs e)
        {
            WebView.CoreWebView2.Navigate("http://" + TBIP.Text + "");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(!robotControlEnabled)
            {
                EnableRobotControl(true);
            }
        }

        private void EnableRobotControl(bool enable)
        {
            robotControlEnabled = enable;
            // Enable or disable other form controls based on the robot control status
            foreach (Control control in Controls)
            {
                control.Enabled = !enable;
            }
        }

        private async void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (TBIP.Text.Length > 4)
            {
                if (e.KeyCode == Keys.Up)
                {
                    await SendCommand("~");
                }
                else if (e.KeyCode == Keys.Down)
                {
                    await SendCommand("@");
                }
                else if (e.KeyCode == Keys.Left)
                {
                    await SendCommand("Q");
                }
                else if (e.KeyCode == Keys.Right)
                {
                    await SendCommand("$");
                }
            }
        }

        private async Task SendCommand(string command)
        {
            if (command != "X")
                speed = speed + accelaration;

            if (speed > 255)
                speed = 255;
            else if (speed < 200)
                speed = 200;

            string url = $"http://{TBIP.Text}/controlBot"; // Change IP address to your NodeMCU's IP
            string data = $"?direction={command}&speed={speed}"; // Change speed as needed
            try
            {
                HttpResponseMessage response = await client.GetAsync(url + data);
                response.EnsureSuccessStatusCode();
                Debug.WriteLine("Sent: " + url + data);
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Error sending command: " + ex.Message);
            }
        }

        private async void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            speed = 200;
            await SendCommand("X");
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == Keys.Escape && robotControlEnabled)
            {
                EnableRobotControl(false);
                return true; // Mark the key as handled
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }
    }
}
