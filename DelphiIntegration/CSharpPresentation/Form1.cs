using System;
using System.Windows.Forms;
using CLIWrapper;

namespace CSharpPresentation
{
    public partial class Form1 : Form
    {
        FooBar myFooBar;

        public Form1()
        {
            InitializeComponent();
            FooBar.Initialize(); 

        }

        ~Form1()
        {
            myFooBar.Dispose();
            FooBar.TearDown();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void BtnCreateFoobar_Click(object sender, EventArgs e)
        {
            myFooBar = new FooBar();
            Label_Foo.Text = "Foo = " + myFooBar.GetFooValue();
        }
    }
}
