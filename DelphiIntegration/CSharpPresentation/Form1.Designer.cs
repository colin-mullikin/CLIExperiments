namespace CSharpPresentation
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.BtnCreateFoobar = new System.Windows.Forms.Button();
            this.Label_Foo = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BtnCreateFoobar
            // 
            this.BtnCreateFoobar.Location = new System.Drawing.Point(12, 12);
            this.BtnCreateFoobar.Name = "BtnCreateFoobar";
            this.BtnCreateFoobar.Size = new System.Drawing.Size(103, 23);
            this.BtnCreateFoobar.TabIndex = 0;
            this.BtnCreateFoobar.Text = "Create FooBar";
            this.BtnCreateFoobar.UseVisualStyleBackColor = true;
            this.BtnCreateFoobar.Click += new System.EventHandler(this.BtnCreateFoobar_Click);
            // 
            // Label_Foo
            // 
            this.Label_Foo.AutoSize = true;
            this.Label_Foo.Location = new System.Drawing.Point(185, 17);
            this.Label_Foo.Name = "Label_Foo";
            this.Label_Foo.Size = new System.Drawing.Size(37, 13);
            this.Label_Foo.TabIndex = 1;
            this.Label_Foo.Text = "Foo = ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.Label_Foo);
            this.Controls.Add(this.BtnCreateFoobar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BtnCreateFoobar;
        private System.Windows.Forms.Label Label_Foo;
    }
}

