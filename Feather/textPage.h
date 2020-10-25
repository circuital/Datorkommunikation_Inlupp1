const char *text_page PROGMEM = R"=====(<!DOCTYPE html>
<html>
<head>
  <title>TEXTPAGE</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
  
  <style>
    body {position: absolute; width: 100%; height: 100%;}
  </style>

</head>
<body>
  
  
  <div class="container mt-5 text-center">
    <form id="textForm">
      <label for="textBox">Write your text here:</label>
      <input id="textBox" type="text" ></input>
      <button id="textBox" type="submit">Submit</button>
    </form>
  </div>
  
  <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js"></script>
  
  <script>
    $(function()
    {
      $("#textForm").on("submit", function(e)
      {
        e.preventDefault();
        let textValue = $("#textBox").val();
        if(textValue !== "")
        {
          fetch(`/api-textPage?text=${textValue}`)
          .then($("#textBox").val(""))
        }
      })
    })
  </script>
  
</body>
</html>)=====";
