const argumentInput = document.getElementById("argumentInput");
const argumentOutput = document.getElementById("argumentOutput");
const flagInputTable = document.getElementById("flagInput");
const addFlag = document.getElementById("addFlag");
const flagOutput = document.getElementById("flagOutput");

// short is one character long
// long is in this form: --in-lower-case
let registeredFlags = [];
let outputArguments = [];

// ------------------ Flag input ------------------
// todo: bring flags into correct format, show visual indicator if something is not correct (and exclude it from registeredFlags)
function updateRegisteredFlag(inputElement, key) {
  let success = false;

  document.querySelectorAll("#flagInput tr").forEach((element, i) => {
    if(element.contains(inputElement)) {
      let value = inputElement.value === "on" ? inputElement.checked : inputElement.value;

      switch(key) {
        case "short":
          for(let character of value.split("")) {
            if(/^[a-zA-Z]$/.exec(character)) {
              if(success) {
                success = false;
                value = undefined;
                break;
              }

              value = character;
              success = true;
            }
          }

          break;
        case "long":
          value = value.toLowerCase();
          value = value.replaceAll("-", " ");
          value = value.replaceAll(/[^a-z ]/g, "");
          value = value.replaceAll(/\s+/g, " ");
          value = value.trim();
          value = value.replaceAll(" ", "-");
          value = "--" + value;

          if(value === "--") {
            inputElement.classList.add("incorrect");
          } else {
            inputElement.classList.remove("incorrect");
          }

          success = value !== "--";

          break;
      }

      if(!success) {
        inputElement.classList.add("incorrect");
      } else {
        inputElement.classList.remove("incorrect");
      }

      registeredFlags[i-1]["visible"] = value;
      registeredFlags[i-1][key] = value;
    }
  });

  parseData();
}

addFlag.onclick = function() {
  registeredFlags.push({short: "", long: "", hasArgument: false, isSet: false, argument: undefined, visible: false});

  let row = flagInputTable.insertRow(document.querySelectorAll("#flagInput tr").length);

  let cell0 = row.insertCell(0);
  let cell1 = row.insertCell(1);
  let cell2 = row.insertCell(2);
  let cell3 = row.insertCell(3);

  cell0.innerHTML = "<input type='text' placeholder='-f' style='width: 100%'>";
  cell1.innerHTML = "<input type='text' placeholder='--file' style='width: 100%'>";
  cell2.innerHTML = "<input type='checkbox'>";

  cell0.oninput = () => {updateRegisteredFlag(cell0.children[0], "short")};
  cell1.oninput = () => {updateRegisteredFlag(cell1.children[0], "long")};
  cell2.oninput = () => {updateRegisteredFlag(cell2.children[0], "hasArgument")};

  cell3.innerHTML = "<button class='button-primary'>✖</button>";
  cell3.children[0].onclick = function() {
    document.querySelectorAll("#flagInput tr").forEach((element, i) => {
      if(element.contains(cell3.children[0])) {
        element.remove();
        registeredFlags.splice(i-1, 1);
      }
    });

    parseData();
  }

  parseData();

  // javascript is something else
}

// ---------------- Parse arguments ----------------
argumentInput.oninput = function() {
  parseData();
};

function parseData() {
  // Reset registered flags
  for(let key in registeredFlags) {
    registeredFlags[key]["isSet"] = false;
    registeredFlags[key]["argument"] = undefined;
  }

  // Split arguments
  let arguments = [];
  let argumentIndex = 0;
  let isQuotes = false;
  let lastChar = undefined;

  for(let character of argumentInput.value.split("")) {
    if(character === " " && !isQuotes) {
      if(lastChar === undefined || lastChar === " ") {
        continue;
      }

      argumentIndex++;
    } else if(character === "\"" && (!isQuotes ? (lastChar === " " || lastChar === undefined) : true)) {
      isQuotes = !isQuotes;
    } else {
      if(arguments.length < argumentIndex+1) {
        arguments.push("");
      }

      arguments[argumentIndex] = arguments[argumentIndex] + character;
    }

    lastChar = character;
  }

  // Parse arguments
  outputArguments = [];
  let argumentBelongsToFlag = undefined;

  for(let argument of arguments) {
    if(argument === "-") continue;

    // Flags
    if(argument.length >= 2 && argument.charAt(0) === "-") {
      if(argument.charAt(1) !== "-") {
        if(argument.length === 2) argumentBelongsToFlag = argument.charAt(1);

        for(let character of argument) {
          if(/^[a-zA-Z]$/.exec(character) && registeredFlags.filter((value) => value.short === character).length !== 0) {
            registeredFlags[registeredFlags.findIndex((value) => value.short === character)].isSet = true;
          }
        }

        continue;
      } else {
        if(registeredFlags.filter((value) => value.long === argument).length !== 0) {
          let i = registeredFlags.findIndex((value) => value.long === argument);

          registeredFlags[i].isSet = true;

          if(registeredFlags[i].hasArgument) {
            argumentBelongsToFlag = registeredFlags[i].short;
          }
        }

        continue;
      }
    }

    if(argumentBelongsToFlag === undefined) {
      outputArguments.push(argument)
    } else {
      if(registeredFlags.filter((value) => value.short === argumentBelongsToFlag).length !== 0) {
        registeredFlags[registeredFlags.findIndex((value) => value.short === argumentBelongsToFlag)].argument = argument;
      }

      argumentBelongsToFlag = undefined;
    }
  }

  // Show work
  outputData();
}

// -------------------- Output ---------------------
function outputData() {
  document.querySelectorAll("#flagOutput tr, #argumentOutput tr").forEach((element) => {
    if(element.children[0].tagName !== "TH") {
      element.remove();
    }
  });

  // Flags
  for(let flag of registeredFlags) {
    if(!flag.visible) continue;

    let row = flagOutput.insertRow(document.querySelectorAll("#flagOutput tr").length);
    let cell0 = row.insertCell(0);
    let cell1 = row.insertCell(1);
    let cell2 = row.insertCell(2);

    cell0.innerText = flag.short;
    cell1.innerHTML = flag.isSet ? "<span style='color: limegreen;'>✓</span>" : "<span style='color: red;'>✕</span>";
    cell2.innerText = flag.argument !== undefined ? flag.argument : "---";
  }

  // Arguments
  for(let argument of outputArguments) {
    let row = argumentOutput.insertRow(document.querySelectorAll("#argumentOutput tr").length);
    let cell = row.insertCell(0);

    cell.innerText = argument;
  }
}
