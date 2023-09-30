

const totalscore={'computerScore' : 0, 'playerScore' : 0}

function getComputerChoice() {
    const rpsChoice = ["Rock","Paper","Scissors"]
    const randomChoice = Math.floor(Math.random()*3)
    return rpsChoice[randomChoice]
}   

function getResult(playerChoice, computerChoice) { 
  let score;
  if(playerChoice == computerChoice){
    score=0
  }
  else if(playerChoice == "Rock" && computerChoice == "Scissors"){
    score=1;
  }  
  else if(playerChoice == "Scissors" && computerChoice == "Paper"){
    score=1;
  }  
  else if(playerChoice == "Paper" && computerChoice == "Rock"){
    score=1;
  }
  else{
    score=-1;
  }
  return score;
}


function showResult(score, playerChoice, computerChoice) {
  const resultDiv = document.getElementById('result')
  const handsDiv = document.getElementById('hands')
  const playerScoreDiv = document.getElementById('player-score')

  if(score==-1){
    resultDiv.innerText = 'You loose!'
  }
  else if(score==0){
    resultDiv.innerText = 'It is an Draw'
  }
  else{
    resultDiv.innerText = 'You won the match'
  }

  handsDiv.innerText = `${playerChoice} vs ${computerChoice}`
  playerScoreDiv.innerText = `Your score: ${totalscore['playerScore']}`
  endGameButton.onclick = () => endGame(totalscore)
}

function onClickRPS(playerChoice) {
  console.log({playerChoice})
  const computerChoice = getComputerChoice()
  console.log({computerChoice})
  const score = getResult(playerChoice,computerChoice)
  totalscore['playerScore'] += score;
  console.log(score)
  showResult(score,playerChoice,computerChoice)
}



function playGame() {
  const rpsButtons = document.querySelectorAll('.rpsButton')
  rpsButtons.forEach(rpsButton=>{
    rpsButton.onclick = () => onClickRPS(rpsButton.value)  
  })
  
}


function endGame(totalscore) {
  totalscore['playerScore'] = 0;
  totalscore['computerScore'] = 0; 
  const resultDiv = document.getElementById('result')
  const handsDiv = document.getElementById('hands')
  const playerScoreDiv = document.getElementById('player-score')
  resultDiv.innerText = ''
  handsDiv.innerText = ''
  playerScoreDiv.innerText = ''
}

playGame()