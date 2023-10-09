function fetchBoard() {
  var board;
  board = ["", "", "", "", "", "", "", "", ""];
  $("#tictac td").each(function (index) {
    board[index] = $(this).text();
  });
  return board;
}
function checkRow(a, b, c) {
  if (a === "X" && b === "X" && c === "X") {
    return 1;
  } else if (a === "O" && b === "O" && c === "O") {
    return -1;
  } else {
    return 0;
  }
}
function checkWin(board) {
  return (
    checkRow(board[0], board[1], board[2]) +
    checkRow(board[3], board[4], board[5]) +
    checkRow(board[6], board[7], board[8]) +
    checkRow(board[0], board[3], board[6]) +
    checkRow(board[1], board[4], board[7]) +
    checkRow(board[2], board[5], board[8]) +
    checkRow(board[0], board[4], board[8]) +
    checkRow(board[2], board[4], board[6])
  );
}
function selectMove(board) {
  var i, options;
  options = [];
  for (i = 0; i < 9; i += 1) {
    if (board[i] === "") {
      options.push(i);
    }
  }
  if (options.length === 0) {
    return -1;
  } else {
    return options[Math.floor(Math.random() * options.length)];
  }
}
function showGameOver(result) {
  var target;
  target = $("#result");
  if (result > 0) {
    target.text("X win!");
  } else if (result < 0) {
    target.text("O win!");
  } else {
    target.text("Draw");
  }
}
$(document).ready(function () {
  var ordi = "O";
  var ordiVal = "O";
  var player = "X";
  $(".playerPick").click(function () {
    player = $(this).val();
    ordi = "";
    if (player == "X") {
      ordi = "O";
      ordiVal = "O";
      $("#tictac td").text("");
    } else {
      ordi = "X";
      ordiVal = "X";
      $("#tictac td").text("");
    }
    $("#result").text("You are currently playing as " + player);
  });
  $("#tictac td").click(function () {
    var xCell, board, result, oLocation, oCell;
    xCell = $(this);
    if (xCell.text() !== "" || checkWin(fetchBoard()) !== 0) {
      return;
    }
    xCell.text(player);
    board = fetchBoard();
    result = checkWin(board);
    if (result !== 0) {
      showGameOver(result);
      return;
    }
    ordi = selectMove(board);
    if (ordi < 0) {
      showGameOver(0);
      return;
    }
    board[ordi] = ordi;
    oCell = $("#cell" + ordi);
    oCell.text(ordiVal);
    board = fetchBoard();
    result = checkWin(board);
    if (result !== 0) {
      showGameOver(result);
      return;
    }
  });
  $("#reset").click(function () {
    $("#tictac td").text("");
    $("#result").text("You are currently playing as " + player);
  });
});


