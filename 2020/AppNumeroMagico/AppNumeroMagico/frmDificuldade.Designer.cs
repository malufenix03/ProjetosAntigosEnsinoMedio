namespace AppNumeroMagico
{
    partial class frmDificuldade
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmDificuldade));
            this.lblSelecione = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.radFacil = new System.Windows.Forms.RadioButton();
            this.radMedio = new System.Windows.Forms.RadioButton();
            this.radDificil = new System.Windows.Forms.RadioButton();
            this.radAdivinho = new System.Windows.Forms.RadioButton();
            this.picFacil = new System.Windows.Forms.PictureBox();
            this.picDificil = new System.Windows.Forms.PictureBox();
            this.picAdivinho = new System.Windows.Forms.PictureBox();
            this.picMedio = new System.Windows.Forms.PictureBox();
            this.btnJogar = new System.Windows.Forms.Button();
            this.lblNTentativas = new System.Windows.Forms.Label();
            this.btnVoltar = new System.Windows.Forms.Button();
            this.btnSair = new System.Windows.Forms.Button();
            this.lblFraseDerrota = new System.Windows.Forms.Label();
            this.lblNumero = new System.Windows.Forms.Label();
            this.txtTentativa2 = new System.Windows.Forms.TextBox();
            this.txtTentativa3 = new System.Windows.Forms.TextBox();
            this.txtTentativa5 = new System.Windows.Forms.TextBox();
            this.txtTentativa4 = new System.Windows.Forms.TextBox();
            this.txtTentativa1 = new System.Windows.Forms.TextBox();
            this.btnEnviar = new System.Windows.Forms.Button();
            this.lblTentativa4 = new System.Windows.Forms.Label();
            this.lblTentativa2 = new System.Windows.Forms.Label();
            this.lblTentativa3 = new System.Windows.Forms.Label();
            this.lblTentativa5 = new System.Windows.Forms.Label();
            this.lblTentativa1 = new System.Windows.Forms.Label();
            this.btnMudar = new System.Windows.Forms.Button();
            this.btnNovo = new System.Windows.Forms.Button();
            this.lblDificuldade = new System.Windows.Forms.Label();
            this.lblArmazenaNumero = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picFacil)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picDificil)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picAdivinho)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picMedio)).BeginInit();
            this.SuspendLayout();
            // 
            // lblSelecione
            // 
            this.lblSelecione.AutoSize = true;
            this.lblSelecione.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSelecione.Location = new System.Drawing.Point(244, 190);
            this.lblSelecione.Name = "lblSelecione";
            this.lblSelecione.Size = new System.Drawing.Size(276, 22);
            this.lblSelecione.TabIndex = 0;
            this.lblSelecione.Text = "Selecione a dificuldade do jogo";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Cooper Black", 66F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.DodgerBlue;
            this.label2.Location = new System.Drawing.Point(2, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(739, 101);
            this.label2.TabIndex = 1;
            this.label2.Text = "Número Mágico";
            // 
            // radFacil
            // 
            this.radFacil.AutoSize = true;
            this.radFacil.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radFacil.Location = new System.Drawing.Point(52, 260);
            this.radFacil.Name = "radFacil";
            this.radFacil.Size = new System.Drawing.Size(60, 22);
            this.radFacil.TabIndex = 2;
            this.radFacil.TabStop = true;
            this.radFacil.Text = "Fácil";
            this.radFacil.UseVisualStyleBackColor = true;
            this.radFacil.CheckedChanged += new System.EventHandler(this.radFacil_CheckedChanged);
            // 
            // radMedio
            // 
            this.radMedio.AutoSize = true;
            this.radMedio.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radMedio.Location = new System.Drawing.Point(225, 260);
            this.radMedio.Name = "radMedio";
            this.radMedio.Size = new System.Drawing.Size(70, 22);
            this.radMedio.TabIndex = 3;
            this.radMedio.TabStop = true;
            this.radMedio.Text = "Médio";
            this.radMedio.UseVisualStyleBackColor = true;
            this.radMedio.CheckedChanged += new System.EventHandler(this.radMedio_CheckedChanged);
            // 
            // radDificil
            // 
            this.radDificil.AutoSize = true;
            this.radDificil.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radDificil.Location = new System.Drawing.Point(393, 260);
            this.radDificil.Name = "radDificil";
            this.radDificil.Size = new System.Drawing.Size(64, 22);
            this.radDificil.TabIndex = 4;
            this.radDificil.TabStop = true;
            this.radDificil.Text = "Difícil";
            this.radDificil.UseVisualStyleBackColor = true;
            this.radDificil.CheckedChanged += new System.EventHandler(this.radDificil_CheckedChanged);
            // 
            // radAdivinho
            // 
            this.radAdivinho.AutoSize = true;
            this.radAdivinho.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radAdivinho.Location = new System.Drawing.Point(556, 260);
            this.radAdivinho.Name = "radAdivinho";
            this.radAdivinho.Size = new System.Drawing.Size(86, 22);
            this.radAdivinho.TabIndex = 5;
            this.radAdivinho.TabStop = true;
            this.radAdivinho.Text = "Adivinho";
            this.radAdivinho.UseVisualStyleBackColor = true;
            this.radAdivinho.CheckedChanged += new System.EventHandler(this.radAdivinho_CheckedChanged);
            // 
            // picFacil
            // 
            this.picFacil.Image = ((System.Drawing.Image)(resources.GetObject("picFacil.Image")));
            this.picFacil.Location = new System.Drawing.Point(109, 257);
            this.picFacil.Name = "picFacil";
            this.picFacil.Size = new System.Drawing.Size(32, 25);
            this.picFacil.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picFacil.TabIndex = 6;
            this.picFacil.TabStop = false;
            // 
            // picDificil
            // 
            this.picDificil.Image = ((System.Drawing.Image)(resources.GetObject("picDificil.Image")));
            this.picDificil.Location = new System.Drawing.Point(463, 257);
            this.picDificil.Name = "picDificil";
            this.picDificil.Size = new System.Drawing.Size(32, 25);
            this.picDificil.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picDificil.TabIndex = 7;
            this.picDificil.TabStop = false;
            // 
            // picAdivinho
            // 
            this.picAdivinho.Image = ((System.Drawing.Image)(resources.GetObject("picAdivinho.Image")));
            this.picAdivinho.Location = new System.Drawing.Point(648, 257);
            this.picAdivinho.Name = "picAdivinho";
            this.picAdivinho.Size = new System.Drawing.Size(32, 25);
            this.picAdivinho.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picAdivinho.TabIndex = 8;
            this.picAdivinho.TabStop = false;
            // 
            // picMedio
            // 
            this.picMedio.Image = ((System.Drawing.Image)(resources.GetObject("picMedio.Image")));
            this.picMedio.Location = new System.Drawing.Point(301, 257);
            this.picMedio.Name = "picMedio";
            this.picMedio.Size = new System.Drawing.Size(32, 25);
            this.picMedio.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picMedio.TabIndex = 9;
            this.picMedio.TabStop = false;
            // 
            // btnJogar
            // 
            this.btnJogar.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnJogar.Enabled = false;
            this.btnJogar.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnJogar.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnJogar.Location = new System.Drawing.Point(12, 349);
            this.btnJogar.Name = "btnJogar";
            this.btnJogar.Size = new System.Drawing.Size(124, 51);
            this.btnJogar.TabIndex = 10;
            this.btnJogar.Text = "&Jogar";
            this.btnJogar.UseVisualStyleBackColor = false;
            this.btnJogar.Click += new System.EventHandler(this.btnJogar_Click);
            // 
            // lblNTentativas
            // 
            this.lblNTentativas.AutoSize = true;
            this.lblNTentativas.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNTentativas.ForeColor = System.Drawing.SystemColors.Highlight;
            this.lblNTentativas.Location = new System.Drawing.Point(49, 299);
            this.lblNTentativas.Name = "lblNTentativas";
            this.lblNTentativas.Size = new System.Drawing.Size(0, 19);
            this.lblNTentativas.TabIndex = 11;
            // 
            // btnVoltar
            // 
            this.btnVoltar.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnVoltar.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnVoltar.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnVoltar.Location = new System.Drawing.Point(301, 349);
            this.btnVoltar.Name = "btnVoltar";
            this.btnVoltar.Size = new System.Drawing.Size(138, 51);
            this.btnVoltar.TabIndex = 12;
            this.btnVoltar.Text = "&Voltar ";
            this.btnVoltar.UseVisualStyleBackColor = false;
            this.btnVoltar.Click += new System.EventHandler(this.btnVoltar_Click);
            // 
            // btnSair
            // 
            this.btnSair.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnSair.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSair.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSair.Location = new System.Drawing.Point(604, 349);
            this.btnSair.Name = "btnSair";
            this.btnSair.Size = new System.Drawing.Size(124, 51);
            this.btnSair.TabIndex = 13;
            this.btnSair.Text = "Sai&r";
            this.btnSair.UseVisualStyleBackColor = false;
            this.btnSair.Click += new System.EventHandler(this.btnSair_Click);
            // 
            // lblFraseDerrota
            // 
            this.lblFraseDerrota.AutoSize = true;
            this.lblFraseDerrota.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFraseDerrota.Location = new System.Drawing.Point(502, 189);
            this.lblFraseDerrota.Name = "lblFraseDerrota";
            this.lblFraseDerrota.Size = new System.Drawing.Size(118, 19);
            this.lblFraseDerrota.TabIndex = 58;
            this.lblFraseDerrota.Text = "O número era:";
            this.lblFraseDerrota.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblFraseDerrota.Visible = false;
            // 
            // lblNumero
            // 
            this.lblNumero.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lblNumero.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblNumero.Font = new System.Drawing.Font("Arial Black", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNumero.ForeColor = System.Drawing.Color.DodgerBlue;
            this.lblNumero.Location = new System.Drawing.Point(476, 220);
            this.lblNumero.Name = "lblNumero";
            this.lblNumero.Size = new System.Drawing.Size(173, 85);
            this.lblNumero.TabIndex = 57;
            this.lblNumero.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblNumero.Visible = false;
            // 
            // txtTentativa2
            // 
            this.txtTentativa2.Enabled = false;
            this.txtTentativa2.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTentativa2.Location = new System.Drawing.Point(127, 255);
            this.txtTentativa2.Name = "txtTentativa2";
            this.txtTentativa2.Size = new System.Drawing.Size(81, 22);
            this.txtTentativa2.TabIndex = 2;
            this.txtTentativa2.Visible = false;
            // 
            // txtTentativa3
            // 
            this.txtTentativa3.Enabled = false;
            this.txtTentativa3.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTentativa3.Location = new System.Drawing.Point(127, 285);
            this.txtTentativa3.Name = "txtTentativa3";
            this.txtTentativa3.Size = new System.Drawing.Size(81, 22);
            this.txtTentativa3.TabIndex = 3;
            this.txtTentativa3.Visible = false;
            // 
            // txtTentativa5
            // 
            this.txtTentativa5.Enabled = false;
            this.txtTentativa5.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTentativa5.Location = new System.Drawing.Point(316, 273);
            this.txtTentativa5.Name = "txtTentativa5";
            this.txtTentativa5.Size = new System.Drawing.Size(81, 22);
            this.txtTentativa5.TabIndex = 5;
            this.txtTentativa5.Visible = false;
            // 
            // txtTentativa4
            // 
            this.txtTentativa4.Enabled = false;
            this.txtTentativa4.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTentativa4.Location = new System.Drawing.Point(316, 233);
            this.txtTentativa4.Name = "txtTentativa4";
            this.txtTentativa4.Size = new System.Drawing.Size(81, 22);
            this.txtTentativa4.TabIndex = 4;
            this.txtTentativa4.Visible = false;
            // 
            // txtTentativa1
            // 
            this.txtTentativa1.Enabled = false;
            this.txtTentativa1.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTentativa1.Location = new System.Drawing.Point(127, 219);
            this.txtTentativa1.Name = "txtTentativa1";
            this.txtTentativa1.Size = new System.Drawing.Size(81, 22);
            this.txtTentativa1.TabIndex = 1;
            this.txtTentativa1.Visible = false;
            // 
            // btnEnviar
            // 
            this.btnEnviar.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnEnviar.Enabled = false;
            this.btnEnviar.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEnviar.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnEnviar.Location = new System.Drawing.Point(12, 349);
            this.btnEnviar.Name = "btnEnviar";
            this.btnEnviar.Size = new System.Drawing.Size(124, 51);
            this.btnEnviar.TabIndex = 6;
            this.btnEnviar.Text = "&Enviar resposta";
            this.btnEnviar.UseVisualStyleBackColor = false;
            this.btnEnviar.Visible = false;
            this.btnEnviar.Click += new System.EventHandler(this.btnEnviar_Click);
            // 
            // lblTentativa4
            // 
            this.lblTentativa4.AutoSize = true;
            this.lblTentativa4.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTentativa4.Location = new System.Drawing.Point(228, 235);
            this.lblTentativa4.Name = "lblTentativa4";
            this.lblTentativa4.Size = new System.Drawing.Size(82, 18);
            this.lblTentativa4.TabIndex = 50;
            this.lblTentativa4.Text = "Tentativa 4";
            this.lblTentativa4.Visible = false;
            // 
            // lblTentativa2
            // 
            this.lblTentativa2.AutoSize = true;
            this.lblTentativa2.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTentativa2.Location = new System.Drawing.Point(39, 251);
            this.lblTentativa2.Name = "lblTentativa2";
            this.lblTentativa2.Size = new System.Drawing.Size(82, 18);
            this.lblTentativa2.TabIndex = 49;
            this.lblTentativa2.Text = "Tentativa 2";
            this.lblTentativa2.Visible = false;
            // 
            // lblTentativa3
            // 
            this.lblTentativa3.AutoSize = true;
            this.lblTentativa3.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTentativa3.Location = new System.Drawing.Point(39, 284);
            this.lblTentativa3.Name = "lblTentativa3";
            this.lblTentativa3.Size = new System.Drawing.Size(82, 18);
            this.lblTentativa3.TabIndex = 48;
            this.lblTentativa3.Text = "Tentativa 3";
            this.lblTentativa3.Visible = false;
            // 
            // lblTentativa5
            // 
            this.lblTentativa5.AutoSize = true;
            this.lblTentativa5.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTentativa5.Location = new System.Drawing.Point(228, 273);
            this.lblTentativa5.Name = "lblTentativa5";
            this.lblTentativa5.Size = new System.Drawing.Size(82, 18);
            this.lblTentativa5.TabIndex = 47;
            this.lblTentativa5.Text = "Tentativa 5";
            this.lblTentativa5.Visible = false;
            // 
            // lblTentativa1
            // 
            this.lblTentativa1.AutoSize = true;
            this.lblTentativa1.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTentativa1.Location = new System.Drawing.Point(39, 219);
            this.lblTentativa1.Name = "lblTentativa1";
            this.lblTentativa1.Size = new System.Drawing.Size(82, 18);
            this.lblTentativa1.TabIndex = 46;
            this.lblTentativa1.Text = "Tentativa 1";
            this.lblTentativa1.Visible = false;
            // 
            // btnMudar
            // 
            this.btnMudar.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnMudar.Enabled = false;
            this.btnMudar.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMudar.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMudar.Location = new System.Drawing.Point(302, 349);
            this.btnMudar.Name = "btnMudar";
            this.btnMudar.Size = new System.Drawing.Size(125, 51);
            this.btnMudar.TabIndex = 8;
            this.btnMudar.Text = "&Mudar dificuldade";
            this.btnMudar.UseVisualStyleBackColor = false;
            this.btnMudar.Visible = false;
            this.btnMudar.Click += new System.EventHandler(this.btnMudar_Click);
            // 
            // btnNovo
            // 
            this.btnNovo.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnNovo.Enabled = false;
            this.btnNovo.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnNovo.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnNovo.Location = new System.Drawing.Point(159, 349);
            this.btnNovo.Name = "btnNovo";
            this.btnNovo.Size = new System.Drawing.Size(124, 51);
            this.btnNovo.TabIndex = 7;
            this.btnNovo.Text = "&Novo";
            this.btnNovo.UseVisualStyleBackColor = false;
            this.btnNovo.Visible = false;
            this.btnNovo.Click += new System.EventHandler(this.btnNovo_Click);
            // 
            // lblDificuldade
            // 
            this.lblDificuldade.AutoSize = true;
            this.lblDificuldade.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDificuldade.Location = new System.Drawing.Point(8, 160);
            this.lblDificuldade.Name = "lblDificuldade";
            this.lblDificuldade.Size = new System.Drawing.Size(105, 22);
            this.lblDificuldade.TabIndex = 43;
            this.lblDificuldade.Text = "Dificuldade";
            this.lblDificuldade.Visible = false;
            // 
            // lblArmazenaNumero
            // 
            this.lblArmazenaNumero.AutoSize = true;
            this.lblArmazenaNumero.Location = new System.Drawing.Point(27, 18);
            this.lblArmazenaNumero.Name = "lblArmazenaNumero";
            this.lblArmazenaNumero.Size = new System.Drawing.Size(0, 13);
            this.lblArmazenaNumero.TabIndex = 59;
            this.lblArmazenaNumero.Visible = false;
            // 
            // frmDificuldade
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(740, 412);
            this.Controls.Add(this.lblArmazenaNumero);
            this.Controls.Add(this.lblFraseDerrota);
            this.Controls.Add(this.lblNumero);
            this.Controls.Add(this.txtTentativa2);
            this.Controls.Add(this.txtTentativa3);
            this.Controls.Add(this.txtTentativa5);
            this.Controls.Add(this.txtTentativa4);
            this.Controls.Add(this.txtTentativa1);
            this.Controls.Add(this.btnEnviar);
            this.Controls.Add(this.lblTentativa4);
            this.Controls.Add(this.lblTentativa2);
            this.Controls.Add(this.lblTentativa3);
            this.Controls.Add(this.lblTentativa5);
            this.Controls.Add(this.lblTentativa1);
            this.Controls.Add(this.btnMudar);
            this.Controls.Add(this.btnNovo);
            this.Controls.Add(this.lblDificuldade);
            this.Controls.Add(this.btnSair);
            this.Controls.Add(this.btnVoltar);
            this.Controls.Add(this.lblNTentativas);
            this.Controls.Add(this.btnJogar);
            this.Controls.Add(this.picMedio);
            this.Controls.Add(this.picAdivinho);
            this.Controls.Add(this.picDificil);
            this.Controls.Add(this.picFacil);
            this.Controls.Add(this.radAdivinho);
            this.Controls.Add(this.radDificil);
            this.Controls.Add(this.radMedio);
            this.Controls.Add(this.radFacil);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lblSelecione);
            this.Name = "frmDificuldade";
            this.Text = "Número Mágico";
            ((System.ComponentModel.ISupportInitialize)(this.picFacil)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picDificil)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picAdivinho)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picMedio)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblSelecione;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton radFacil;
        private System.Windows.Forms.RadioButton radMedio;
        private System.Windows.Forms.RadioButton radDificil;
        private System.Windows.Forms.RadioButton radAdivinho;
        private System.Windows.Forms.PictureBox picFacil;
        private System.Windows.Forms.PictureBox picDificil;
        private System.Windows.Forms.PictureBox picAdivinho;
        private System.Windows.Forms.PictureBox picMedio;
        private System.Windows.Forms.Button btnJogar;
        private System.Windows.Forms.Label lblNTentativas;
        private System.Windows.Forms.Button btnVoltar;
        private System.Windows.Forms.Button btnSair;
        private System.Windows.Forms.Label lblFraseDerrota;
        private System.Windows.Forms.Label lblNumero;
        private System.Windows.Forms.TextBox txtTentativa2;
        private System.Windows.Forms.TextBox txtTentativa3;
        private System.Windows.Forms.TextBox txtTentativa5;
        private System.Windows.Forms.TextBox txtTentativa4;
        private System.Windows.Forms.TextBox txtTentativa1;
        private System.Windows.Forms.Button btnEnviar;
        private System.Windows.Forms.Label lblTentativa4;
        private System.Windows.Forms.Label lblTentativa2;
        private System.Windows.Forms.Label lblTentativa3;
        private System.Windows.Forms.Label lblTentativa5;
        private System.Windows.Forms.Label lblTentativa1;
        private System.Windows.Forms.Button btnMudar;
        private System.Windows.Forms.Button btnNovo;
        private System.Windows.Forms.Label lblDificuldade;
        private System.Windows.Forms.Label lblArmazenaNumero;
    }
}