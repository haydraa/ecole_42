export async function PongStartTournament() {

  function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
  }

  let player1_name = document.querySelector('#player1').textContent;
  let player2_name = document.querySelector('#player2').textContent;


  // Define the canvas and context
  let canvas = document.getElementById('pongCanvas');
  let context = canvas.getContext('2d');

  let player1Score = 0;
  let player2Score = 0;

  // pong.js
  window.addEventListener('resize', () => {
    // Update the canvas size to match the actual size of the canvas element
    canvas.width = canvas.innerWidth;
    canvas.height = canvas.innerHeight;
    // paddleWidth = canvas.width / 5;

    // Redraw the game or adjust game elements to fit the new size
  });


  // Define the paddles
  let paddleWidth = 5;;
  let paddleHeight = canvas.height / 5;
  let paddle1 = { x: 0, y: canvas.height / 2 - paddleHeight / 2, dy: 0 };
  let paddle2 = { x: canvas.width - paddleWidth, y: canvas.height / 2 - paddleHeight / 2, dy: 0 };

  // Define the ball
  let ball = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    radius: 5,
    speed: 2, // Desired speed
    dx: 0, // Initialize dx to 0
    dy: 0 // Initialize dy to 0
  };

  // Array of initial directions
  let initialDirections = [
    { dx: 2, dy: -2 },
    { dx: -2, dy: 2 },
    { dx: 2, dy: 2 },
    { dx: -2, dy: -2 }
  ];

  // Function to initialize ball with a random direction from the initialDirections array
  function initializeBall() {
    // Generate a random index between 0 and 3
    let randomPos = Math.floor(Math.random() * 4);

    // Assign the selected direction to the ball
    ball.dx = initialDirections[randomPos].dx;
    ball.dy = initialDirections[randomPos].dy;
  }

  // Call initializeBall at the start of the game or when resetting the game
  initializeBall();

  // Function to draw the paddles
  function drawPaddles() {
    context.fillStyle = 'black';
    context.fillRect(paddle1.x, paddle1.y, paddleWidth, paddleHeight);
    context.fillRect(paddle2.x, paddle2.y, paddleWidth, paddleHeight);
  }

  // Function to draw the ball
  function drawBall() {
    context.beginPath();
    context.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
    context.fillStyle = 'black';
    context.fill();
    context.closePath();
  }

  // Function to clear the canvas
  function clearCanvas() {
    context.clearRect(0, 0, canvas.width, canvas.height);
  }

  // Reset ball position and velocity
  function resetGameState() {
    ball.x = canvas.width / 2;
    ball.y = canvas.height / 2;
    initializeBall();
    ball.speed = 2;

    paddle1.y = canvas.height / 2 - paddleHeight / 2;
    paddle2.y = canvas.height / 2 - paddleHeight / 2;
  }

  function updatePaddles() {
    // Move paddle1 up
    if (paddle1.y > 0 && paddle1.dy < 0) {
      paddle1.y += paddle1.dy;
    }
    // Move paddle1 down
    if (paddle1.y + paddleHeight < canvas.height && paddle1.dy > 0) {
      paddle1.y += paddle1.dy;
    }

    // Move paddle2 up
    if (paddle2.y > 0 && paddle2.dy < 0) {
      paddle2.y += paddle2.dy;
    }
    // Move paddle2 down
    if (paddle2.y + paddleHeight < canvas.height && paddle2.dy > 0) {
      paddle2.y += paddle2.dy;
    }
  }

  let startTime = new Date();
  // Game loop

  async function gameLoop() {
    clearCanvas();
    drawPaddles();
    drawBall();
    aiLoop();

    // Update ball position
    ball.x += ball.dx;
    ball.y += ball.dy;

    let centerX = 0;//canvas.width / 2;
    let centerY = 30;
    let fontSize = canvas.width * 0.05

    context.fillStyle = 'black';
    context.font = `${fontSize}px Arial`;
    context.fillText(`${player1_name} Score: ${player1Score}`, centerX, centerY);
    context.fillText(`${player2_name} Score: ${player2Score}`, canvas.width / 2, centerY);

    if (ball.x - ball.radius < 0) {
      // Ball hit the left edge of the canvas
      // Update the score for player 2
      player2Score++;
      // updateScore('player2', newScore);
      resetGameState();
    } else if (ball.x + ball.radius > canvas.width) {
      // Ball hit the right edge of the canvas
      // Update the score for player 1
      player1Score++;
      // updateScore('player1', newScore);
      resetGameState();
    }


    // Bounce the ball off the paddles
    if (ball.y + ball.radius > paddle1.y && ball.y - ball.radius < paddle1.y + paddleHeight && ball.x - ball.radius < paddle1.x + paddleWidth) {
      ball.dx = -ball.dx * 1.1;
      ball.speed *= 1.1;
    } else if (ball.y + ball.radius > paddle2.y && ball.y - ball.radius < paddle2.y + paddleHeight && ball.x + ball.radius > paddle2.x) {
      ball.dx = -ball.dx * 1.1;
      ball.speed *= 1.1;
    }

    // Bounce the ball off the top and bottom of the canvas
    if (ball.y + ball.radius > canvas.height || ball.y - ball.radius < 0) {
      ball.dy = -ball.dy * 1.1;
      ball.speed *= 1.1;
    }

    updatePaddles();

    if (player1Score >= 3 || player2Score >= 3) {
      gameOver();
      return;
    } else {
      requestAnimationFrame(gameLoop);
    }
  }

  // Start the game loop
  gameLoop();

  // pong.js
  function gameOver() {

    // Get the modal element
    let modal = document.getElementById('gameOverModal');
    let player1ScoreText = document.getElementById('player1ScoreText');
    let player2ScoreText = document.getElementById('player2ScoreText');

    // Update the modal content with the final scores
    player1ScoreText.textContent += `${player1Score}`;
    player2ScoreText.textContent += `${player2Score}`;

    // Show the modal
    modal.style.display = "block";

    // Add an event listener to close the modal when the button is clicked
    document.getElementById('closeModalButton').addEventListener('click', function () {
      modal.style.display = "none";

      // Redirect to the index page
      fetch('/game/result-match-tournament/', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          player1_score: player1Score,
          player2_score: player2Score,
        }),
      })
        .then(response => {
          const contentType = response.headers.get("content-type");

          if (contentType && contentType.includes("application/json")) {
            // Handle JSON response
            return response.json().then(data => {
              // Process JSON data here
              console.log('JSON data:', data);
              endofTournament(data.redirect_url);
            });
          } else if (contentType && contentType.includes("text/html")) {
            // Handle HTML response
            return response.text();
          }
        })
        .then(data => {
          if (typeof data === 'object') {
            console.log('JSON data : ', data);
          }
          else {
            const parser = new DOMParser();
            const doc = parser.parseFromString(data, 'text/html');
            const newBody = doc.body;
            const newHeader = doc.head;
            document.body.innerHTML = newBody.innerHTML;
            document.head.innerHTML = newHeader.innerHTML;
          }
        })
        .catch((error) => { });
    });
  }


  document.addEventListener('keydown', function (event) {
    if (event.key === 'w') {
      paddle1.dy = -5; // Move paddle1 up
    } else if (event.key === 's') {
      paddle1.dy = 5; // Move paddle1 down
    } else if (event.key === 'ArrowUp') {
      paddle2.dy = -5; // Move paddle2 up
    } else if (event.key === 'ArrowDown') {
      paddle2.dy = 5; // Move paddle2 down
    }
  });

  document.addEventListener('keyup', function (event) {
    if (event.key === 'w' || event.key === 's') {
      paddle1.dy = 0; // Stop paddle1 movement
    } else if (event.key === 'ArrowUp' || event.key === 'ArrowDown') {
      paddle2.dy = 0; // Stop paddle2 movement
    }
  });

  function endofTournament(url) {

    fetch(url, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
    })
      .then(response => {
        const contentType = response.headers.get("content-type");

        if (contentType && contentType.includes("application/json")) {
          return response.json();
        }
        else if (contentType && contentType.includes("text/html")) {
          return response.text();
        }
      })
      .then(data => {
        if (typeof data === 'object') {
          console.log('JSON data : ', data);
        }
        else {
          const parser = new DOMParser();
          const doc = parser.parseFromString(data, 'text/html');
          const newBody = doc.body;
          const newHeader = doc.head;
          document.body.innerHTML = newBody.innerHTML;
          document.head.innerHTML = newHeader.innerHTML;
          returnButton();
        }
      })
      .catch((error) => { });
  }

  function returnButton() {

    const nav = document.querySelector('#tournament');
    if (nav) {
      nav.addEventListener('click', function (event) {
        // Check if the clicked element is the button you're interested in
        if (event.target.id === 'returnTournament') {
          event.preventDefault();
          fetch('/game/delTournament/', {
            method: 'POST',
            headers: {
              'Content-Type': 'application/json',
            },
          })
            .then(response => {
              const contentType = response.headers.get("content-type");

              if (contentType && contentType.includes("application/json")) {
                return response.json();
              }
              else if (contentType && contentType.includes("text/html")) {
                return response.text();
              }
            })
            .then(data => {
              if (typeof data === 'object') {
                console.log('JSON data : ', data);
              }
              else {
                const parser = new DOMParser();
                const doc = parser.parseFromString(data, 'text/html');
                const newBody = doc.body;
                const newHeader = doc.head;
                document.body.innerHTML = newBody.innerHTML;
                document.head.innerHTML = newHeader.innerHTML;
                history.pushState(null, null, '/game_menu/');
                returnButton();
              }
            })
            .catch((error) => { });
        }
      });
    }
  }
}