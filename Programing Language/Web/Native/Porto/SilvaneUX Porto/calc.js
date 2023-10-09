jQuery(document).ready(function ($) {
  $("#ynumber1").on("keyup", function () {
    var ynumber1 = parseInt($(this).val());
    var ynumber2 = parseInt($("#ynumber2").val());
    var opsi = $("#opsi").val();

    if (opsi == "+") {
      total = ynumber1 + ynumber2;
    } else if (opsi == "-") {
      total = ynumber1 - ynumber2;
    } else if (opsi == "x") {
      total = ynumber1 * ynumber2;
    } else if (opsi == ":") {
      total = ynumber1 / ynumber2;
    } else {
      total = ynumber1 % ynumber2;
    }

    $("#ytotal").val(total);
  });

  $("#ynumber2").on("keyup", function () {
    var ynumber1 = parseInt($("#ynumber1").val());
    var ynumber2 = parseInt($(this).val());
    var opsi = $("#opsi").val();

    if (opsi == "+") {
      total = ynumber1 + ynumber2;
    } else if (opsi == "-") {
      total = ynumber1 - ynumber2;
    } else if (opsi == "x") {
      total = ynumber1 * ynumber2;
    } else if (opsi == ":") {
      total = ynumber1 / ynumber2;
    } else {
      total = ynumber1 % ynumber2;
    }

    $("#ytotal").val(total);
  });

  $("#opsi").on("change", function () {
    var ynumber1 = parseInt($("#ynumber1").val());
    var ynumber2 = parseInt($("#ynumber2").val());
    var opsi = $(this).val();
    if (opsi == "+") {
      total = ynumber1 + ynumber2;
    } else if (opsi == "-") {
      total = ynumber1 - ynumber2;
    } else if (opsi == "x") {
      total = ynumber1 * ynumber2;
    } else if (opsi == ":") {
      total = ynumber1 / ynumber2;
    } else {
      total = ynumber1 % ynumber2;
    }

    $("#ytotal").val(total);
  });
});
