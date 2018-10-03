/*
 * The MIT License
 *
 * Copyright 2017-2018 Norwegian University of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef FMI4CPP_SPECIFICMODELDESCRIPTION_HPP
#define FMI4CPP_SPECIFICMODELDESCRIPTION_HPP

#include <type_traits>
#include "ModelDescription.hpp"
#include "SourceFiles.hpp"

namespace fmi4cpp::fmi2::xml {

    template <class T>
    class SpecificModelDescription : public virtual ModelDescription {

//        static_assert(std::is_base_of<xml::FmuTypeAttributes, T>::value, "T must derive from FmuTypeAttributes");

    private:
        const ModelDescription &modelDescription_;

    protected:
        const T &data_;

    public:

        SpecificModelDescription(const ModelDescription &md, const T &data)
                : modelDescription_(md), data_(data) {}

        const ScalarVariable &getVariableByValueReference(const fmi2ValueReference vr) const {
            return modelDescription_.getVariableByValueReference(vr);
        }

        const ScalarVariable &getVariableByName(const string &name) const {
            return modelDescription_.getVariableByName(name);
        }

        bool supportsCoSimulation() const {
            return modelDescription_.supportsCoSimulation();
        }

        bool supportsModelExchange() const {
            return modelDescription_.supportsModelExchange();
        }

        std::optional<DefaultExperiment> getDefaultExperiment() const {
            return modelDescription_.getDefaultExperiment();
        }

        const ModelStructure &getModelStructure() const {
            return modelDescription_.getModelStructure();
        }

        const ModelVariables &getModelVariables() const {
            return modelDescription_.getModelVariables();
        }

        size_t getNumberOfContinuousStates() const {
            return modelDescription_.getNumberOfContinuousStates();
        }

        size_t getNumberOfEventIndicators() const {
            return modelDescription_.getNumberOfEventIndicators();
        }

        std::string getVariableNamingConvention() const {
            return modelDescription_.getVariableNamingConvention();
        }

        std::string getGenerationDateAndTime() const {
            return modelDescription_.getGenerationDateAndTime();
        }

        std::string getGenerationTool() const {
            return modelDescription_.getGenerationTool();
        }

        std::string getCopyright() const {
            return modelDescription_.getCopyright();
        }

        std::string getLicense() const {
            return modelDescription_.getLicense();
        }

        std::string getAuthor() const {
            return modelDescription_.getAuthor();
        }

        std::string getVersion() const {
            return modelDescription_.getVersion();
        }

        std::string getDescription() const {
            return modelDescription_.getDescription();
        }

        std::string getModelName() const {
            return modelDescription_.getModelName();
        }

        std::string getFmiVersion() const {
            return modelDescription_.getFmiVersion();
        }

        std::string getGuid() const {
            return modelDescription_.getGuid();
        }

        SourceFiles getSourceFiles() const {
            return data_.sourceFiles;
        }

        bool providesDirectionalDerivative() const {
            return data_.providesDirectionalDerivative;
        }

        bool canBeInstantiatedOnlyOncePerProcess() const {
            return data_.canBeInstantiatedOnlyOncePerProcess;
        }

        bool canNotUseMemoryManagementFunctions() const {
            return data_.canNotUseMemoryManagementFunctions;
        }

        bool needsExecutionTool() const {
            return data_.needsExecutionTool;
        }

        bool canSerializeFMUstate() const {
            return data_.canSerializeFMUstate;
        }

        bool canGetAndSetFMUstate() const {
            return data_.canGetAndSetFMUstate;
        }

        string getModelIdentifier() const {
            return data_.modelIdentifier;
        }

    };

    class CoSimulationModelDescription : public SpecificModelDescription<CoSimulationAttributes> {

    public:

        explicit CoSimulationModelDescription(const ModelDescription &md, const CoSimulationAttributes &data);

        bool canInterpolateInputs() const;

        bool canRunAsynchronuously() const;

        bool canHandleVariableCommunicationStepSize() const;

        size_t maxOutputDerivativeOrder() const;

    };

    class ModelExchangeModelDescription : public SpecificModelDescription<ModelExchangeAttributes> {

    public:
        explicit ModelExchangeModelDescription(const ModelDescription &md, const ModelExchangeAttributes &data);

        bool completedIntegratorStepNotNeeded() const;

    };

}


#endif //FMI4CPP_SPECIFICMODELDESCRIPTION_HPP
