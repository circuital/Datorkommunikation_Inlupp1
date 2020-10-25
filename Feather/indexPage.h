const char *index_page PROGMEM = R"=====(<!DOCTYPE html>
<html>
<head>
  <title>INDEXPAGE</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
  
  <style>
    body {position: absolute; width: 100%; height: 100%;}
    #label {display: block;}
  </style>

</head>
<body>

  <div class="container mt-5 text-center">
      <label for="temperature">Temperature:</label>
      <div id="temperature"></div>
      <label for="humidity">Humidity:</label>
      <div id="humidity"></div>
      <a href="http://172.20.216.24/textPage">Click here to submit your own text!</a> 
  </div>
  
  <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js"></script>
  
  <script>
    $(function()
    {
      function getTempHum()
      {
        fetch("/api-indexPage")
        .then(res => res.json())
        .then(data =>
        {
          if(data.temperature !== "")
          {
            $("#temperature").html(data.temperature + " grader Celcius");
          }
          if(data.humidity !== "")
          {
            $("#humidity").html(data.humidity + " %");
          }
        })
      }
      setInterval(getTempHum, 1000);
    })
 
  </script>
</body>
</html>)=====";
