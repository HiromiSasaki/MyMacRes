using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;

namespace LogisticMapForm
{
    public partial class logisticMapForm : Form
    {
        double[] xdata = new double[5000];
        /// <summary>
        /// [0:4]
        /// </summary>
        public double ParamA = 0;
        public OpenTK.GLControl MainGlControl;
        private bool mainGlControlIsLoaded = false;
        public logisticMapForm()
        {
            InitializeComponent();
            mainGlControlIsLoaded = true;
            MainGlControl = glControl;
            glControl.Load += glControl_Load;
            glControl.Resize += glControl_Resize;
            returnMapGlControl.Load += returnMapGlControl_Load;
            returnMapGlControl.Resize += returnMapGlControl_Resize;
        }

        void returnMapGlControl_Resize(object sender, EventArgs e)
        {
            if (!mainGlControlIsLoaded)
                return;
            // 今回は発生しない
            SetupViewport();
        }

        void returnMapGlControl_Load(object sender, EventArgs e)
        {
            mainGlControlIsLoaded = true;
            // 初期化処理はここで
            SetupViewport();
            GL.ClearColor(Color.Black);
        }

        void glControl_Resize(object sender, EventArgs e)
        {
            if (!mainGlControlIsLoaded)
                return;
            // 今回は発生しない
            SetupViewport();
        }

        void glControl_Load(object sender, EventArgs e)
        {
            mainGlControlIsLoaded = true;
            // 初期化処理はここで
            SetupViewport();
            GL.ClearColor(Color.Black);
        }

        private void SetupViewport()
        {
            int w = glControl.Width;
            int h = glControl.Height;

            GL.MatrixMode(MatrixMode.Projection);
            GL.LoadIdentity();
            GL.Ortho(0, w, 0, h, -1, 1); // Bottom-left corner pixel has coordinate (0, 0)
            GL.Viewport(0, 0, w, h); // Use all of the glControl painting area
        }

        private void resetButton_Click(object sender, EventArgs e)
        {
            glControl.MakeCurrent();
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.Color3(Color.White);
            
            double x = 0.001;
            for (int i = 0; i < xdata.Length; i++)
            {
                xdata[i] = x;
                x = ParamA * x * (1 - x);
            }
            // 左下が0,0
            GL.Begin(PrimitiveType.LineStrip);
            {
                int c = 0;
                for (int i = 0; i < glControl.Width; i += 5)
                {
                    GL.Vertex2(i, xdata[4000 + c] * glControl.Height);
                    c++;
                }
            }
            GL.End();
            double x0 = x;
            int period = 0;
            for (period = 0; period < 200; period++)
            {
                x = ParamA * x * (1 - x);
                if (Math.Abs(x0 - x) < 1.0e-6)
                    break;
            }
            if (period != 200)
                this.periodLabel.Text = "Period = " + (period + 1);
            else
                this.periodLabel.Text = "Period = None";

            this.paramALabel.Text = "a = " + this.ParamA;

            glControl.SwapBuffers();

            returnMapGlControl.MakeCurrent();
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.Color3(Color.Blue);
            int width = returnMapGlControl.Width;
            int height = returnMapGlControl.Height;
            GL.Begin(PrimitiveType.LineStrip);
            for (int i = 0; i < width; i++)
            {
                double x1 = (double)i / width * 1.0;
                double y1 = ParamA * x1 * (1 - x1);
                GL.Vertex2(i, y1 * returnMapGlControl.Height);
            }
            GL.End();

            GL.Color3(Color.Green);
            GL.Begin(PrimitiveType.LineStrip);
            GL.Vertex2(0, 0);
            GL.Vertex2(width, height);
            GL.End();

            GL.Color3(Color.White);
            GL.Begin(PrimitiveType.LineStrip);

            for (int i = 0; i < 300; i++)
            {
                GL.Vertex2(xdata[4000 + i] * width, xdata[4000 + i + 1] * height);
                GL.Vertex2(xdata[4000 + i + 1] * width, xdata[4000 + i + 1] * height);
            }
            GL.End();
            GL.Color3(Color.Pink);
            GL.PointSize(8);
            GL.Begin(PrimitiveType.Points);

            for (int i = 0; i < 300; i++)
            {
                GL.Vertex2(xdata[4000 + i] * width, xdata[4000 + i + 1] * height);
            }
            GL.End();

            returnMapGlControl.SwapBuffers();
        }

        private void paramTrackBar_ValueChanged(object sender, EventArgs e)
        {
            glControl.MakeCurrent();
            this.ParamA = paramTrackBar.Value / 1000.0;

            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.Color3(Color.White);
            double x = 0.001;

            for (int i = 0; i < xdata.Length; i++)
            {
                xdata[i] = x;
                x = ParamA * x * (1 - x);
            }
            // 左下が0,0
            GL.Begin(PrimitiveType.LineStrip);
            {
                int c = 0;
                for (int i = 0; i < glControl.Width; i += 5)
                {
                    GL.Vertex2(i, xdata[c] * glControl.Height);
                    c++;
                }
            }
            GL.End();
            double x0 = x;
            int period = 0;
            for (period = 0; period < 200; period++)
            {
                x = ParamA * x * (1 - x);
                if (Math.Abs(x0 - x) < 1.0e-6)
                    break;
            }
            if (period != 200)
                this.periodLabel.Text = "Period = " + (period + 1);
            else
                this.periodLabel.Text = "Period = None";
            this.paramALabel.Text = "a = " + this.ParamA;

            glControl.SwapBuffers();


            returnMapGlControl.MakeCurrent();
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.Color3(Color.Blue);
            int width = returnMapGlControl.Width;
            int height = returnMapGlControl.Height;
            GL.Begin(PrimitiveType.LineStrip);
            for (int i = 0; i < width; i++)
            {
                double x1 = (double)i / width * 1.0;
                double y1 = ParamA * x1 * (1 - x1);
                GL.Vertex2(i, y1 * returnMapGlControl.Height);
            }
            GL.End();

            GL.Color3(Color.Green);
            GL.Begin(PrimitiveType.LineStrip);
            GL.Vertex2(0, 0);
            GL.Vertex2(width, height);
            GL.End();

            GL.Color3(Color.White);
            GL.Begin(PrimitiveType.LineStrip);

            GL.Vertex2(xdata[0] * width, 0);

            for (int i = 0; i < 300; i++)
            {
                GL.Vertex2(xdata[i] * width, xdata[i + 1] * height);
                GL.Vertex2(xdata[i + 1] * width, xdata[i + 1] * height);
            }
            GL.End();

            returnMapGlControl.SwapBuffers();
        }
    }
}
