// copied from https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
//g++ `pkg-config --cflags gtk+-3.0` -o app gui.c `pkg-config --libs gtk+-3.0`

#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


// boolean variables
gboolean trigger_buttonSCL = FALSE;
gboolean trigger_buttonSDA = FALSE;
gboolean trigger_buttonSCK = FALSE;
gboolean trigger_buttonMISO = FALSE;
gboolean trigger_buttonMOSI = FALSE;
gboolean trigger_buttonSS = FALSE;

int speed = 0;

const char* header = "<!DOCTYPE html>\n<head>\n<title>\nArduino control page\n</title>\n<link rel='stylesheet' href='styles.css'>\n</head>\n<body>\n<h1>You are on arduino control page.</h1>\n<details>\n\n<p>@00000000000000000000000000000000</p>\n\n<p>@10241024102410241024102410241024</p>\n\n<p>@09201024000400011024000000000000</p>\n\n<p>@10241024102410241024102410241024</p>\n\n<p>@09201024000400011024000000000000</p>\n\n<p>@";

const char* command = "00000000000000000000000000000000";

char* command_line = (char*)command;

const char* tail = "</p>\n\n\n</details>\n\n\n<details>\n<summary>explanation</summary>\n\n<p>Arduino based devices come to this page and red the information (<a href='instructions.txt'>more</a>).</p>\n\n\n\n</details>\n\n\n</body>\n</html>";


char status_SCL = '0';
char status_SDA = '0';
char status_SCK = '0';
char status_MISO = '0';
char status_MOSI = '0';
char status_SS = '0';

char status_speed = '0';


static void
function_buttonSCL (GtkWidget *widget,
             gpointer   data )
{
	trigger_buttonSCL = !trigger_buttonSCL;
  	g_print ("buttonSCL");
	if (trigger_buttonSCL) {

		status_SCL = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();

	};


	if (!trigger_buttonSCL) {

		status_SCL = '0';

		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();

	};

}




static void
function_buttonSDA (GtkWidget *widget,
             gpointer   data)
{
	trigger_buttonSDA = !trigger_buttonSDA;
  	g_print ("buttonSDA");


	if (trigger_buttonSDA) {

		status_SDA = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();

	};


	if (!trigger_buttonSDA) {

		status_SDA = '0';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();

	};
}




static void
function_buttonSCK (GtkWidget *widget,
             gpointer   data)
{
	trigger_buttonSCK = !trigger_buttonSCK;
  	g_print ("buttonSCK");

	if (trigger_buttonSCK) {

		status_SCK = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};


	if (!trigger_buttonSCK) {

		status_SCK = '0';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};
}



static void
function_buttonMISO (GtkWidget *widget,
             gpointer   data)
{
	trigger_buttonMISO = !trigger_buttonMISO;
  	g_print ("buttonMISO");

	if (trigger_buttonMISO) {


		status_MISO = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};


	if (!trigger_buttonMISO) {

		status_MISO = '0';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};
}



static void
function_buttonMOSI (GtkWidget *widget,
             gpointer   data)
{
	trigger_buttonMOSI = !trigger_buttonMOSI;
  	g_print ("buttonMOSI");

	if (trigger_buttonMOSI) {

		status_MOSI = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};


	if (!trigger_buttonMOSI) {

		status_MOSI = '0';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};
}



static void
function_buttonSS (GtkWidget *widget,
             gpointer   data)
{
	trigger_buttonSS = !trigger_buttonSS;
  	g_print ("buttonSS");

	if (trigger_buttonSS) {

		status_SS = '1';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};


	if (!trigger_buttonSS) {

		status_SS = '0';


		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();
	};
}



// speed function

static void
function_button100ms (GtkWidget *widget,
             gpointer   data)
{

		status_speed = '2';

		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();


}

static void
function_button500ms (GtkWidget *widget,
             gpointer   data)
{

		status_speed = '1';

		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();


}

static void
function_button5s (GtkWidget *widget,
             gpointer   data)
{

		status_speed = '0';

		fstream my_file;
		my_file.open("index.html", ios::out);
		const char* zeroes = "0000000000000000000000000";
		my_file << header;
		my_file << status_SCL;
		my_file << status_SDA;
		my_file << status_SCK;
		my_file << status_MISO;
		my_file << status_MOSI;
		my_file << status_SS;
		my_file << status_speed;
		my_file << zeroes;
		my_file << tail;
		my_file.close();


}





// function draw all the elements
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;



	// Add as many names buttons as you want
  GtkWidget *buttonSCL,*buttonSDA,*buttonSCK,*buttonMISO,*buttonMOSI,*buttonSS, *button100ms, *button500ms, *button5s;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Command post");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 400);

  //button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);



	// Add as many buttons as you want

	buttonSCL = gtk_button_new_with_label ("SCL");
	buttonSDA = gtk_button_new_with_label ("SDA");
	buttonSCK = gtk_button_new_with_label ("SCK");
	buttonMISO = gtk_button_new_with_label ("MISO");
	buttonMOSI = gtk_button_new_with_label ("MOSI");
	buttonSS = gtk_button_new_with_label ("SS");

	button100ms = gtk_button_new_with_label ("100ms");
	button500ms = gtk_button_new_with_label ("500ms");
	button5s = gtk_button_new_with_label ("5s");



	// For each button you need that block
	//second stroke is for ending the application
 // g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
 // gtk_container_add (GTK_CONTAINER (button_box), button);

	g_signal_connect (buttonSCL, "clicked", G_CALLBACK (function_buttonSCL), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonSCL);

	g_signal_connect (buttonSDA, "clicked", G_CALLBACK (function_buttonSDA), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonSDA);

	g_signal_connect (buttonSCK, "clicked", G_CALLBACK (function_buttonSCK), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonSCK);

	g_signal_connect (buttonMISO, "clicked", G_CALLBACK (function_buttonMISO), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonMISO);

	g_signal_connect (buttonMOSI, "clicked", G_CALLBACK (function_buttonMOSI), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonMOSI);

	g_signal_connect (buttonSS, "clicked", G_CALLBACK (function_buttonSS), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), buttonSS);



	g_signal_connect (button100ms, "clicked", G_CALLBACK (function_button100ms), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), button100ms);

	g_signal_connect (button500ms, "clicked", G_CALLBACK (function_button500ms), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), button500ms);

	g_signal_connect (button5s, "clicked", G_CALLBACK (function_button5s), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), button5s);



  gtk_widget_show_all (window);
}


// main function
int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}