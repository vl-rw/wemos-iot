const http = require("http");
const fs = require("fs");


// for wifi6
let data = '';

let head = '';
let wifi1 = '';
let wifi2 = '';
let wifi3 = '';
let wifi4 = '';
let wifi5 = '';
let wifi6 = '';
let tail = '';
let el_end = '</p>\n\n<p>'

let full_page ='';

// function to write file - it necessary to make logical
// variables cause it writes actually TWO TIMES
// so if it switches to 1, it returns to 0
// for logical variables - it chages onse and writes 1 two times

trigger_buttonSCL = false;
trigger_buttonSDA = false;
trigger_buttonSCK = false;
trigger_buttonMISO = false;
trigger_buttonMOSI = false;
trigger_buttonSS = false;

let speed = 0;



function change_info() {

	console.log('change info!');
	let wifi6_changeable = wifi6.split('');

	if (trigger_buttonSCL) {
		wifi6_changeable[0] = "1";
	} else {
		wifi6_changeable[0] = "0";
	};
	if (trigger_buttonSDA) {
		wifi6_changeable[1] = "1";
	} else {
		wifi6_changeable[1] = "0";
	};
	if (trigger_buttonSCK) {
		wifi6_changeable[2] = "1";
	} else {
		wifi6_changeable[2] = "0";
	};
	if (trigger_buttonMISO) {
		wifi6_changeable[3] = "1";
	} else {
		wifi6_changeable[3] = "0";
	};
	if (trigger_buttonMOSI) {
		wifi6_changeable[4] = "1";
	} else {
		wifi6_changeable[4] = "0";
	};
	if (trigger_buttonSS) {
		wifi6_changeable[5] = "1";
	} else {
		wifi6_changeable[5] = "0";
	};


	// speed change
	if (speed == 0) {
		wifi6_changeable[6] = "0";
	};
	if (speed == 1) {
		wifi6_changeable[6] = "1";
	};
	if (speed == 2) {
		wifi6_changeable[6] = "2";
	};


	wifi6_stroke = wifi6_changeable.join('');

  	full_page = head+'@'+wifi1+el_end+'@'+wifi2+el_end+'@'+wifi3+el_end+'@';
  	full_page += wifi4+el_end+'@'+wifi5+el_end+'@'+wifi6_stroke+el_end+tail;


	fs.writeFile('ind.html', full_page, function(err) {

    	if(err) {

        	return console.log(err);

    	}

    		console.log("The file was saved!");

	});

};



fs.readFile('ind.html', 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }
  	//console.log(data);
	array = data.split('@');
	head = array[0];
	//console.log(array);
	//console.log(array[1]);
	wifi1 = array[1].split('<')[0];
	wifi2 = array[2].split('<')[0];
	wifi3 = array[3].split('<')[0];
	wifi4 = array[4].split('<')[0];
	wifi5 = array[5].split('<')[0];
	wifi6 = array[6].split('<')[0];

	tail = array[6];	//.split('0000')[1];

  	//console.log("TAIL");
  	//console.table(tail.split('</p>')[1]);

  	tail = tail.split('</p>')[1];

});

http.createServer((request, response) => {


	if (request.url === "") {

		console.log("start");

	};

	if (request.url === "/") {

		console.log("start");


	};



	// start control transfer

	if (request.url === "/scl") {

		console.log("scl");
		trigger_buttonSCL = !trigger_buttonSCL;

	};

	if (request.url === "/sda") {

		console.log("sda");
		trigger_buttonSDA = !trigger_buttonSDA;

	};

	if (request.url === "/sck") {

		console.log("sck");
		trigger_buttonSCK = !trigger_buttonSCK;

	};

	if (request.url === "/miso") {

		console.log("miso");
		trigger_buttonMISO = !trigger_buttonMISO;

	};

	if (request.url === "/mosi") {

		console.log("mosi");
		trigger_buttonMOSI = !trigger_buttonMOSI;

	};

	if (request.url === "/ss") {

		console.log("ss");
		trigger_buttonSS = !trigger_buttonSS;

	};


	if (request.url === "/ms100") {

		console.log("100 miliseconds");
		speed = 2;

	};


	if (request.url === "/ms500") {

		console.log("500 miliseconds");
		speed = 1;

	};


	if (request.url === "/s5") {

		console.log("5 seconds");
		speed = 0;

	};

	// for device wifi6, get info

	if (request.url === "/wifi6/a0") console.log(`wifi6 A0 - 0%`);
	if (request.url === "/wifi6/a1") console.log(`wifi6 A0 - 5%`);
	if (request.url === "/wifi6/a2") console.log(`wifi6 A0 - 10%`);
	if (request.url === "/wifi6/a3") console.log(`wifi6 A0 - 15%`);
	if (request.url === "/wifi6/a4") console.log(`wifi6 A0 - 20%`);
	if (request.url === "/wifi6/a5") console.log(`wifi6 A0 - 25%`);
	if (request.url === "/wifi6/a6") console.log(`wifi6 A0 - 30%`);
	if (request.url === "/wifi6/a7") console.log(`wifi6 A0 - 35%`);
	if (request.url === "/wifi6/a8") console.log(`wifi6 A0 - 40%`);
	if (request.url === "/wifi6/a9") console.log(`wifi6 A0 - 45%`);
	if (request.url === "/wifi6/a10") console.log(`wifi6 A0 - 50%`);
	if (request.url === "/wifi6/a11") console.log(`wifi6 A0 - 55%`);
	if (request.url === "/wifi6/a12") console.log(`wifi6 A0 - 60%`);
	if (request.url === "/wifi6/a13") console.log(`wifi6 A0 - 65%`);
	if (request.url === "/wifi6/a14") console.log(`wifi6 A0 - 70%`);
	if (request.url === "/wifi6/a15") console.log(`wifi6 A0 - 75%`);
	if (request.url === "/wifi6/a16") console.log(`wifi6 A0 - 80%`);
	if (request.url === "/wifi6/a17") console.log(`wifi6 A0 - 85%`);
	if (request.url === "/wifi6/a18") console.log(`wifi6 A0 - 90%`);
	if (request.url === "/wifi6/a19") console.log(`wifi6 A0 - 95%`);
	if (request.url === "/wifi6/a20") console.log(`wifi6 A0 - 100%`);

	change_info();

	fs.readFile("ind.html", (error, data) => response.end(data));


}).listen(1200, ()=>console.log("Сервер запущен по адресу http://localhost:1200"));

