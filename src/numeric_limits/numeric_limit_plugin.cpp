#include <sag_connectivity_plugins.hpp>
#include <limits>

using namespace com::softwareag::connectivity;

struct NumericLimitsPlugin : public AbstractTransport {

public:

    /*
     * Populates an event with float, double and integer min/max
     *      event com.numeric.Limit {
     *          integer maxInteger;
     *          integer minInteger;
     *          integer maxFloat;
     *          integer minFloat;
     *          integer maxDouble;
     *          integer minDouble;
     *      }
     */

    NumericLimitsPlugin(const TransportConstructorParameters &params) : AbstractTransport(params) {
        logger.info("Loaded NumericLimitPlugin.");
    }

    void sendBatchTowardsTransport(Message* start, Message* end) {
        for (auto it = start; it != end; ++it) {
            const auto type = it->getMetadata()[Message::HOST_MESSAGE_TYPE()];
            if (type == "com.numeric.LimitsRequest") {
                map_t payload;
                payload["integerMax"] = std::numeric_limits<int64_t>::max();
                payload["integerMin"] = std::numeric_limits<int64_t>::min();
                payload["floatMax"] = std::numeric_limits<float>::max();
                payload["floatMin"] = std::numeric_limits<float>::min();
                payload["doubleMax"] = std::numeric_limits<double>::max();
                payload["doubleMin"] = std::numeric_limits<double>::min();
                Message msg(data_t(std::move(payload)));
                msg.putMetadataValue(Message::HOST_MESSAGE_TYPE(), "com.numeric.Limits");
                hostSide->sendBatchTowardsHost(&msg, &msg + 1);
            }
        }
    }
};

SAG_DECLARE_CONNECTIVITY_TRANSPORT_CLASS(NumericLimitsPlugin);
