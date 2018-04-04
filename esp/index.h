const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
    <script
  src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js""></script>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
    <style>
        body,
        html {
            /* The image used */
            background-image: url("https://www.planwallpaper.com/static/images/Alien_Ink_2560X1600_Abstract_Background_1.jpg");

            /* Full height */
            height: 100%;

            /* Center and scale the image nicely */
            background-position: center;
            background-repeat: no-repeat;
            background-size: cover;
        }

        h1 {
            text-align: center !important;
            font-size: 40px;
        }

        .text-powitalny {
            font-size: 30px;
            text-align: left;
        }
    </style>
</head>

<body>
    <div class="container">
        <div class="row">
            <div class="col">
                <h1>Stacja Pogodowa</h1>
            </div>
        </div>
        <div class="row">
            <div class="col">
                <span class="text-powitalny">Witamy, na naszej stronie sprawdzisz aktualną temperaturę oraz wilgotność. Dane odświeżane są co dwie sekundy.</span>
            </div>
        </div>
        <div class="row">
            <div class="col-6">
                <span class="temperatura">Aktualna temperatura:</span>
            </div>
            <div class="col-6">
                <span class="wiglotnosc">Aktualna wilgotność:</span>
            </div>
        </div>
        <div class="row">
            <div class="col-6">
                <span class="temperatura">Aktualna temperatura:</span>
            </div>
            <div class="col-6">
                <span class="wiglotnosc">Aktualna wilgotność:</span>
            </div>
        </div>
        <div class="row">
            <div class="col-6">
                <span class="temperatura">Aktualna temperatura:</span>
            </div>
            <div class="col-6">
                <span class="wiglotnosc">Aktualna wilgotność:</span>
            </div>
        </div>
    </div>

</body>
</html>
)=====";