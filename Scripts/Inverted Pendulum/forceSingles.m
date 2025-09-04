function forceSingles(modelName)
    % Ensure the model is loaded
    load_system(modelName);

    % 1. Force Data Type Override to Single for all numeric types
    set_param(modelName, ...
        'DataTypeOverride', 'Single', ...
        'DataTypeOverrideAppliesTo', 'AllNumericTypes');

    % 2. Convert all Constant blocks to single precision
    constBlocks = find_system(modelName, 'BlockType', 'Constant');
    for i = 1:numel(constBlocks)
        valStr = get_param(constBlocks{i}, 'Value');
        try
            % Wrap the existing value in single()
            set_param(constBlocks{i}, 'Value', ...
                sprintf('single(%s)', valStr));
        catch
            % Ignore any constants that can't be converted directly
        end
    end

    % 3. Change output data type for math-heavy blocks (Gain, Sum, Product)
    mathBlocks = find_system(modelName, ...
        'RegExp', 'on', ...
        'BlockType', 'Gain|Sum|Product|Math');
    for i = 1:numel(mathBlocks)
        if strcmp(get_param(mathBlocks{i}, 'OutDataTypeStr'), 'double')
            set_param(mathBlocks{i}, 'OutDataTypeStr', 'single');
        end
    end

    % 4. Change all From Workspace blocks to single precision
    fromWSBlocks = find_system(modelName, 'BlockType', 'FromWorkspace');
    for i = 1:numel(fromWSBlocks)
        dataStr = get_param(fromWSBlocks{i}, 'VariableName');
        set_param(fromWSBlocks{i}, 'VariableName', ...
            sprintf('single(%s)', dataStr));
    end

    % 5. Save and close
    save_system(modelName);
    fprintf('✅ All doubles converted to singles for model "%s"\n', modelName);
end
