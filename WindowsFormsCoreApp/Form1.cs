using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsCoreApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            var host = new MyAxHost();
            host.Dock = DockStyle.Fill;
            Controls.Add(host);
        }
    }

    public class MyAxHost : AxHost
    {
        public MyAxHost() : base("ec408006-9af7-48ea-af51-9743e2efde6f")
        {
        }
    }
}
