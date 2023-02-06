const http = require("http");
const fs = require("fs");

//export PATH=$PATH:/home/pc/node-v17.3.0-linux-x64/bin
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
	//console.log(wifi6_stroke);

  	full_page = head+'@'+wifi1+el_end+'@'+wifi2+el_end+'@'+wifi3+el_end+'@';
  	//full_page += wifi4+el_end+'@'+wifi5+el_end+'@'+wifi6_stroke+el_end+tail;
  	full_page += wifi4+el_end+'@'+wifi5+el_end+'@'+wifi6_stroke+'</p>'+tail;
	//console.log(full_page);
	//console.log(tail);
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



const server = http.createServer((request, response) => {


	if (request.url === "") {

		//console.log("request for command");

	};

	if (request.url === "request for command") {

		//console.log("start");


	};



	// start control transfer

	if (request.url === "/scl") {

		console.log("scl");
		trigger_buttonSCL = !trigger_buttonSCL;
		change_info();

	};

	if (request.url === "/sda") {

		console.log("sda");
		trigger_buttonSDA = !trigger_buttonSDA;
		change_info();

	};

	if (request.url === "/sck") {

		console.log("sck");
		trigger_buttonSCK = !trigger_buttonSCK;
		change_info();

	};

	if (request.url === "/miso") {

		console.log("miso");
		trigger_buttonMISO = !trigger_buttonMISO;
		change_info();

	};

	if (request.url === "/mosi") {

		console.log("mosi");
		trigger_buttonMOSI = !trigger_buttonMOSI;
		change_info();

	};

	if (request.url === "/ss") {

		console.log("ss");
		trigger_buttonSS = !trigger_buttonSS;
		change_info();

	};


	if (request.url === "/ms100") {

		console.log("100 miliseconds");
		speed = 2;
		change_info();

	};


	if (request.url === "/ms500") {

		console.log("500 miliseconds");
		speed = 1;
		change_info();

	};


	if (request.url === "/s5") {

		console.log("5 seconds");
		speed = 0;
		change_info();

	};

	if (request.url === "/wifi6/a0") process.stdout.write(`wifi6 A0 - 0%\r`);
	if (request.url === "/wifi6/a1") process.stdout.write(`wifi6 A0 - 5%\r`);
	if (request.url === "/wifi6/a2") process.stdout.write(`wifi6 A0 - 10%\r`);
	if (request.url === "/wifi6/a3") process.stdout.write(`wifi6 A0 - 15%\r`);
	if (request.url === "/wifi6/a4") process.stdout.write(`wifi6 A0 - 20%\r`);
	if (request.url === "/wifi6/a5") process.stdout.write(`wifi6 A0 - 25%\r`);
	if (request.url === "/wifi6/a6") process.stdout.write(`wifi6 A0 - 30%\r`);
	if (request.url === "/wifi6/a7") process.stdout.write(`wifi6 A0 - 35%\r`);
	if (request.url === "/wifi6/a8") process.stdout.write(`wifi6 A0 - 40%\r`);
	if (request.url === "/wifi6/a9") process.stdout.write(`wifi6 A0 - 45%\r`);
	if (request.url === "/wifi6/a10") process.stdout.write(`wifi6 A0 - 50%\r`);
	if (request.url === "/wifi6/a11") process.stdout.write(`wifi6 A0 - 55%\r`);
	if (request.url === "/wifi6/a12") process.stdout.write(`wifi6 A0 - 60%\r`);
	if (request.url === "/wifi6/a13") process.stdout.write(`wifi6 A0 - 65%\r`);
	if (request.url === "/wifi6/a14") process.stdout.write(`wifi6 A0 - 70%\r`);
	if (request.url === "/wifi6/a15") process.stdout.write(`wifi6 A0 - 75%\r`);
	if (request.url === "/wifi6/a16") process.stdout.write(`wifi6 A0 - 80%\r`);
	if (request.url === "/wifi6/a17") process.stdout.write(`wifi6 A0 - 85%\r`);
	if (request.url === "/wifi6/a18") process.stdout.write(`wifi6 A0 - 90%\r`);
	if (request.url === "/wifi6/a19") process.stdout.write(`wifi6 A0 - 95%\r`);
	if (request.url === "/wifi6/a20") process.stdout.write(`wifi6 A0 - 100%\r`);
	//change_info();

	fs.readFile("ind.html", (error, data) => response.end(data));


});


//const wss = new WebSocket.Server({ noServer: true });
//server.listen(1200, '127.0.0.1');
server.listen(1200);
console.log('Go to 192.168.0.1:1200');

