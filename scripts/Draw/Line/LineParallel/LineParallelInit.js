function init(basePath) {
    var action = new RGuiAction(qsTranslate("LineParallel", "Para&llel (with Distance)"),
        RMainWindowQt.getMainWindow());
    action.setRequiresDocument(true);
    action.setScriptFile(basePath + "/LineParallel.js");
    action.setIcon(basePath + "/LineParallel.svg");
    action.setStatusTip(qsTranslate("LineParallel", "Draw parallel to existing line " +
                             "or concentric arc, circle"));
    action.setDefaultShortcuts([
                            new QKeySequence("l,p"),
                            new QKeySequence("p,a"),
                            new QKeySequence("o,f")
                        ]);
    action.setDefaultCommands([
        "lineparallel", "lineoffset", "offset",
        "o", "parallel", "par",
        "lp", "pa", "of"
    ]);
    action.setSortOrder(800);
    EAction.addGuiActionTo(action, Line, true, true, true, true);
}
